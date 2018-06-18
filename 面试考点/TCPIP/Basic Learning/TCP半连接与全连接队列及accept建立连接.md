>> 学习网站:http://www.omnisecu.com/

1. SYN队列（半连接队列）|ACCEPT队列（全连接队列）
2. TCP握手过程中建连接的流程和队列
![](三次握手（半连接全连接）.jpg)
3. 注意两个队列取出关系
![](queue.png)

## 队满时会发生什么
- 为什么有的应用服务器进程，会单独使用一个线程去调用accept来建立服务端和客户端的连接，比如tomcat；而有的则是一个线程做所有的事，即获取连接后还会做I/O等其他操作？
- - 第一种情况：SYN队列满。如果SYN队列满，则会直接丢弃连接请求。 
比如syn floods 攻击就是针对半连接队列（SYN队列）的，攻击方不停地建连接，但是建连接的时候只做第一步，第二步中攻击方收到server的syn+ack后故意扔掉什么也不做，server需要一个超时时间把这个连接断开，否则大量这样的连接导致server上这个队列满其它正常请求无法进来。
- - 第二种情况：ACCEPT队列满。
我的理解是接收ACK的速率非常快，快过了从ACCEPT队列中获取的速率，故ACCEPT队列会满。
- 一般 overflowed 表示全连接队列溢出次数，socket ignored 表示半连接队列溢出次数，这两个是同步增加的，overflow的时候一定会socket ignored++（还是不太理解）
- - 所以对应用服务器进程来说，如果ACCEPT队列中有已经建立好的TCP连接，却没有及时的把它取出来，这样一旦导致两个队列满后就会使客户端不能再建立新的连接，引发严重问题。所以，比如tomcat等服务器会用独立的线程只做accept获取连接这一件事，以防止不能及时的去accept获取连接。
- - 阻塞套接字，accept行为如右
![](阻塞socket.png)
- - 非阻塞套接字，accept行为如右
![](非阻塞socket.png)
- - 所以，企业级的服务器进程中，若某一线程既使用accept获取新连接，又继续在这个连接上读、写字符流，那么，这个连接对应的套接字通常要设为非阻塞。？？
- 若client走完第三步，那么在client看来连接已经建立好了，但是server上实际没有准备好，如果这时候client发数据给server，server怎么处理呢？
- - client发送一个数据包给server后，server上的这个连接实际没有ready，server一直没有回复，一段时间后client认为丢包了，然后重传这个包，一直到超时，client主动发FIN包断开连接。

## linux上的半连接和全连接
- listen()函数的官方文档中说的很清楚，当连接数超过（pending queue，应该是全连接）全连接队列长度时，此时服务器端的处理是由底层协议来决定的。
- listen函数中的第二个参数说是最大连接队列长度，但官方文档说：自linux2.2版本以来，这个参数指全连接队列长度，而不是半连接队列长度。
- 半连接队列长度设置方法：设置/proc/sys/net/ipv4/tcp_max_syn_backlog文件，其中默认值为5。（其中backlog文件只有这一个）
- 若listen函数第二个参数值超过/proc/sys/net/core/somaxconn，则使用此文件中的值，默认值为128。
- 当全连接队列满了，此时server通过 /proc/sys/net/ipv4/tcp_abort_on_overflow 来决定如何返回：
- - tcp_abort_on_overflow 为 0，不会把连接从SYN队列中移除，server过一段时间再次发送syn+ack给client（也就是重新走握手的第二步），这样来回重发几次，次数由 /proc/sys/net/ipv4/tcp_synack_retries(默认为 5 ) 指定，如果三次握手第三步的时候 ACCEPT 队列一直是满，那么server扔掉client 发过来的 ACK（在server端认为连接还没建立起来）；
- - tcp_abort_on_overflow 为 1 表示第三步的时候如果 ACCEPT 队列满了，server发送一个RST包给client，表示废掉这个握手过程和这个连接（本来在server端这个连接就还没建立起来），客户端会出现 connection reset by peer 的异常。
