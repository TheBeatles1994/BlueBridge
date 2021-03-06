# 当在浏览器中输入一个域名后，会发生什么

>> 链接：http://edusagar.com/articles/view/70/What-happens-when-you-type-a-URL-in-browser

>> 链接：https://blog.csdn.net/icsdn51k/article/details/71075489

>> 链接(上一链接的英文版)：http://igoro.com/archive/what-really-happens-when-you-navigate-to-a-url/

>> HTTP：http://www.runoob.com/http/http-intro.html

```
解析：http://mail.163.com/index.html
1) http://:这个是协议，也就是HTTP超文本传输协议，也就是网页在网上传输的协议。
2) mail：这个是服务器名，代表着是一个邮箱服务器，所以是mail.
3) 163.com:这个是域名，是用来定位网站的独一无二的名字。
4) mail.163.com：这个是网站名，由服务器名+域名组成。
5) /：这个是根目录，也就是说，通过网站名找到服务器，然后在服务器存放网页的根目录
6) index.html：这个是根目录下的默认网页（当然，163的默认网页是不是这个我不知道，只是大部分的默认网页，都是index.html）
7) http://mail.163.com/index.html:这个叫做URL，统一资源定位符，全球性地址，用于定位网上的资源。

这个域名和网站名有什么区别？
比如说，你买下了一个大学，这个大学的名字叫：myname.com.
然后，你想建立一个语文系，所以，文科楼建立了，叫yuwen.myname.com
然后，你又想建立一个数学系，OK，shuxue.myname.com建立了。
就像163一样，他的域名是163.com，他想建立一个www服务器，所以有了www.163.com.
他又想玩邮箱服务器，所以，mail.163.com也有了。
```

- 第一步：在浏览器中输入URL
- 第二步：若请求的对象就在浏览器的缓存中，则直接跳向步骤8
- 第三步：DNS查找域名的IP地址
- - 当我们连接google.com时，我们实际想要的是它的ip地址。我们可以输入 "http://74.125.236.65" ,这样也可以跳转到谷歌界面。但这并不意味着这两者是同一个东西。谷歌服务器分布在全球各个地点，因为它每秒要相应无数的请求，所以我们应该让谷歌来帮我们选择最好的服务器地址。而使用域名“google.com”时就会达到我们的要求。DNS服务器会解析此域名并给我们一个最适合的IP地址
- - 如下是DNS工作流程：
- - - 查找浏览器缓存，浏览器会缓存DNS记录一段时间。
- - - 如果在浏览器缓存里没有找到需要的记录，浏览器会做一个系统调用（windows里是gethostbyname）。这样便可获得系统缓存中的记录。
- - - 路由器缓存，路由器中也有自己的DNS缓存
- - - ISP（Internet Service Provider,互联网服务提供商）的DNS服务器缓存。在这一般都能找到相应的缓存记录。(要是还没有的话会执行递归搜索方法，自己没有深究)(特别注意此处DNS会返回一个IP，当然一个域名可能对应多个IP，这里DNS可能会考虑到负载均衡)
- 第四步：浏览器向服务器发送TCP连接请求
- 第五步：浏览器向服务器发送HTTP请求
- - 请求中也包含浏览器存储的该域名的cookies。可能你已经知道，在不同页面请求当中，cookies是与跟踪一个网站状态相匹配的键值。这样cookies会存储登录用户名，服务器分配的密码和一些用户设置等。Cookies会以文本文档形式存储在客户机里，每次请求时发送给服务器。
- - 像http://facebook.com/中的斜杠是至关重要的。这种情况下，浏览器能安全的添加斜杠。而像http://example.com/folderOrFile这样的地址，因为浏览器不清楚folderOrFile到底是文件夹还是文件，所以不能自动添加斜杠。这时，浏览器就不加斜杠直接访问地址，服务器会响应一个重定向（可能是文件夹也可能是文件），结果造成一次不必要的握手。
- - 当输入http://facebook.com/，服务器给浏览器响应一个301永久重定向响应，这样浏览器就会访问“http://www.facebook.com/” 而非“http://facebook.com/”。
- - 为什么服务器一定要重定向而不是直接发会用户想看的网页内容呢:其中一个原因跟搜索引擎排名有关。你看，如果一个页面有两个地址，就像http://www.igoro.com/ 和http://igoro.com/，搜索引擎会认为它们是两个网站，结果造成每一个的搜索链接都减少从而降低排名。而搜索引擎知道301永久重定向是什么意思，这样就会把访问带www的和不带www的地址归到同一个网站排名下。还有一个是用不同的地址会造成缓存友好性变差。当一个页面有好几个名字时，它可能会在缓存里出现好几次。
- 第六步：服务器处理客户端请求
- - web服务器端（如Apache, IIS etc）将请求交给各自的处理器（handler），这个处理器是一段处理web服务的处理程序（PHP, ASP.NET, Ruby, Servlets etc.）
- - 当用户在浏览器输入http://edusagar.com/index.php，服务器端接收到GET请求后，服务器配置好环境并执行index.php程序，这个php程序将生成一个回复内容。(像http://example.com/folder1/page1.aspx这个地址会映射/httpdocs/folder1/page1.aspx这个文件。)
- 第七步：浏览器接收到服务器回复
- 第八步：浏览器显示html内容
- - 在浏览器没有完整接受全部HTML文档时，它就已经开始显示这个页面了（一行一行显示内容）。若发现有图片标签（img src="/assets/img/logo.png" /），浏览器会再次发送GET请求来获取图片（图片，javascript, css会保存在浏览器缓存，故下一次他们不需要再次GET了）
- 第九步：客户端与服务器互动
- - 一旦一个页面已经加载好，用户有很多种方式可以和服务器互动。比如填写用户名。注意填写完毕后点击登录时，客户端会发送POST请求，这个请求是要让服务器端来处理（登录就是处理用户名和密码的合法性）
- - 一旦服务器认证成功，他将发送正确的html内容给客户端，这时客户端会看到新的内容（比如看到自己用户名了）
- 第十步：浏览器发送异步(AJAX)(Asynchronous JavaScript And XML)请求
- - ajax请求运行在后台，它主要是更新页面内容（如显示好友是否在线信息）