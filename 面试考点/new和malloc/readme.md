# malloc和new的异同
## 不同
1. 构造函数： new除了申请空间之外还会调用构造函数，而malloc仅仅是申请空间
2. 类型： new是一个operator运算符，是可以重写的；而malloc是一个函数
3. 返回类型： new返回的是申请类的对象的指针，而malloc返回void*
4. 失败情况：new会throw错误，而malloc会返回NULL
6. override重写：new可以
7. 分配大小：new是编译器为我们分配空间，而malloc是我们手写的空间
## 相同
1. 内存分配：malloc是从heap堆中分配的内存，而new是从自由存储区（free store）获取的，个人理解两个是一样的东西，只是语言不一样所以叫法不一样