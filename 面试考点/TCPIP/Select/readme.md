# select
>> 参考：http://www.lowtek.com/sockets/select.html
>> 参考：http://devarea.com/linux-io-multiplexing-select-vs-poll-vs-epoll/#.Wyd3Thx9huQ
>> 参考：https://blog.csdn.net/davidsguo008/article/details/73556811

## advantage
不用像fork那样，单独开一个进程，一个进程来搞定多个客户端连接。
## disadvantage
使用fork时，整个代码可以表现的就像只处理一个客户端一样，从而比较容易开发。
## select工作方式
在一些文件描述符发生状况前，select函数会阻塞进程。状况包括：文件描述符收到数据，或能够向文件描述符发送数据。


Most select()-based servers look pretty much the same:

    * Fill up a fd_set structure with the file descriptors you want to know when data comes in on. 
    * Fill up a fd_set structure with the file descriptors you want to know when you can write on. 
    * Call select() and block until something happens. 
    * Once select() returns, check to see if any of your file descriptors was the reason you woke up. If so, 'service' that file descriptor in whatever particular way your server needs to (i.e. read in a request for a Web page). 
    * Repeat this process forever. 
