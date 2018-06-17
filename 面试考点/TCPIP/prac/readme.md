>> 参考：http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html
>> 参考：https://www.geeksforgeeks.org/socket-programming-cc/

# 服务器端
1. socket函数和accept函数返回的套接字是文件描述符（file descriptor）。每一个进程都有自己的文件描述符列表，该列表中保存着一些指向i/o流的指针。当一个进程开启时，有三项会自动生成：标准输入（standard input）的文件描述符是 0，标准输出（standard output）是 1，标准错误（standard error）是 2。当一个文件打开时，新的项会生成并写入列表。
2. socket()函数：第一个参数表示地址域，AF_INET表示发生在网络上（specifies  a  communications  domain within which communication will take place）；第二个参数表示协议，此处选择SOCK_STREAM流协议；第三个参数写入0，系统将自动根据前两个参数选择TCP还是UDP。
3. struct sockaddr_in是用来表示网络地址的。其中包括：<br>sin_addr.s_addr：32位无符号整形表示地址<br>sin_family表示地址域，选择AF_INET<br>sin_port表示16位端口
4. bind()函数，用来将套接字和网络地址绑定。
5. listen()函数，用来监听制定套接字端口的连接请求。
6. accept()函数，在客户端连接成功前，此函数会阻塞进程。最后返回一个套接字，即文件描述符。此后所有的读写操作都通过该套接字实现。函数参数包括连接套接字，以及网络地址struct和一个描述struct大小的变量。
7. read()函数，从套接字中读取信息。其中第三个参数若写成255，意思是要么读取最多读取255个。

# 客户端
1. struct hostent：作为gethostbyname的返回值，获取服务器信息，其中h_addr将用来填写到struct sockaddr_in的sin_addr.s_addr中，通过bcopy函数。