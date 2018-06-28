# 宏在C++中的替代解决方案

1. 常量定义：const int NUM = 100;
2. 函数定义：使用内联函数而不是#define
3. 类型重定义：用typedef unsigned int DWORD来代替#define DWORD unsigned int

# 有些不能替代
1. 条件编译。自己经常使用，用于调试；同时还可以用作跨平台；
2. 头文件包含：为了防止头文件重复包含