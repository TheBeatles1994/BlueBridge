# HTTP
## 简介
- HTTP协议是Hyper Text Transfer Protocol（超文本传输协议）的缩写,是用于从万维网（WWW:World Wide Web ）服务器传输超文本到本地浏览器的传送协议。
- HTTP是一个基于TCP/IP通信协议来传递数据（HTML 文件, 图片文件, 查询结果等）。
## 工作原理
- HTTP协议工作于客户端-服务端架构上。浏览器作为HTTP客户端通过URL向HTTP服务端即WEB服务器发送所有请求。
- Web服务器根据接收到的请求后，向客户端发送响应信息。
- HTTP默认端口号为80，但是你也可以改为8080或者其他端口。
- HTTP是无连接：无连接的含义是限制每次连接只处理一个请求。服务器处理完客户的请求，并收到客户的应答后，即断开连接。采用这种方式可以节省传输时间。（短连接？）
- HTTP是无状态：HTTP协议是无状态协议。无状态是指协议对于事务处理没有记忆能力。缺少状态意味着如果后续处理需要前面的信息，则它必须重传，这样可能导致每次连接传送的数据量增大。另一方面，在服务器不需要先前信息时它的应答就较快。
## HTTP消息结构
- HTTP是基于客户端/服务端（C/S）的架构模型，通过一个可靠的链接来交换信息，是一个无状态的请求/响应协议。
- 一个HTTP"客户端"是一个应用程序（Web浏览器或其他任何客户端），通过连接到服务器达到向服务器发送一个或多个HTTP的请求的目的。
- 一个HTTP"服务器"同样也是一个应用程序（通常是一个Web服务，如Apache Web服务器或IIS服务器等），通过接收客户端的请求并向客户端发送HTTP响应数据。
- HTTP使用统一资源标识符（Uniform Resource Identifiers, URI）来传输数据和建立连接。
## 客户端请求消息
- 请求消息包括以下格式：请求行（request line）、请求头部（header）、空行和请求数据四个部分组成

![](客户端请求消息.png)
## 服务器响应消息
- HTTP响应也由四个部分组成，分别是：状态行、消息报头、空行和响应正文。

![](服务器响应消息.jpg)
## 实例
```
//下面实例是一点典型的使用GET来传递数据的实例：
客户端请求：

GET /hello.txt HTTP/1.1
User-Agent: curl/7.16.3 libcurl/7.16.3 OpenSSL/0.9.7l zlib/1.2.3
Host: www.example.com
Accept-Language: en, mi

服务端响应:

HTTP/1.1 200 OK
Date: Mon, 27 Jul 2009 12:28:53 GMT
Server: Apache
Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT
ETag: "34aa387-d-1568eb00"
Accept-Ranges: bytes
Content-Length: 51
Vary: Accept-Encoding
Content-Type: text/plain

输出结果：

Hello World! My payload includes a trailing CRLF.
```
## HTTP请求方式
- HTTP1.0定义了三种请求方法： GET, POST 和 HEAD方法。
- HTTP1.1新增了五种请求方法，可上网查看

方法|描述
---|---
GET|请求指定的页面信息，并返回实体主体。
HEAD|类似于get请求，只不过返回的响应中没有具体的内容，用于获取报头
POST|向指定资源提交数据进行处理请求（例如提交表单或者上传文件）。数据被包含在请求体中。POST请求可能会导致新的资源的建立和/或已有资源的修改。

## HTTP 响应头信息
- HTTP请求头提供了关于请求，响应或者其他的发送实体的信息。

应答头|说明
---|---
Allow|服务器支持哪些请求方法（如GET、POST等）。
Content-Encoding|文档的编码（Encode）方法。
Content-Length|只有当浏览器使用持久HTTP连接时才需要这个数据。
Content-Type|表示后面的文档属于什么MIME类型。Servlet默认为text/plain，但通常需要显式地指定为text/html。由于经常要设置Content-Type，因此HttpServletResponse提供了一个专用的方法setContentType。
Date|当前的GMT时间。
Expires|应该在什么时候认为文档已经过期，从而不再缓存它？
Last-Modified|文档的最后改动时间。客户可以通过If-Modified-Since请求头提供一个日期，该请求将被视为一个条件GET，只有改动时间迟于指定时间的文档才会返回，否则返回一个304（Not Modified）状态。Last-Modified也可用setDateHeader方法来设置。
Location|表示客户应当到哪里去提取文档。
Refresh|表示浏览器应该在多少时间之后刷新文档，以秒计。
Server|服务器名字。Servlet一般不设置这个值，而是由Web服务器自己设置。
Set-Cookie|设置和页面关联的Cookie。
WWW-Authenticate|客户应该在Authorization头中提供什么类型的授权信息？

- 下面是常见的HTTP状态码：

状态码|说明
---|---
1**|仅显示信息
2**|显示成功类型
3**|重定向到其他url
4**|客户端错误
5**|服务器错误
200 | 请求成功
301 | 资源（网页等）被永久转移到其它URL
403| 服务器理解请求客户端的请求，但是拒绝执行此请求
404 | 请求的资源（网页等）不存在
500 | 内部服务器错误