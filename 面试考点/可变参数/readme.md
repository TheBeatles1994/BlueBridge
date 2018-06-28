# 可变参数

## C
### 步骤
1. 函数原型中使用省略号； 
2. 函数定义中创建一个va_list变量； 
3. 初始化va_list变量； 
4. 访问参数列表； 
5. 完成清理工作； 
```
typedef char* va_list;          //字符指针
void va_start ( va_list ap, prev_param ); /* ANSI version */
type va_arg ( va_list ap, type ); 
void va_end ( va_list ap ); 
```
```
/* --sum.cpp-- 可变参数宏实现求任意个整形值的和 */
#include <stdarg.h>

int sum(int count, ...);    　　//原型中使用省略号

int sum(int count, ...){    　　//count 表示可变参数个数
    va_list ap;　　　　　　　　　//声明一个va_list变量
    va_start(ap, count);　　 　 //初始化，第二个参数为最后一个确定的形参

    int sum = 0;  
    for(int i = 0; i < count; i++)          
        sum += va_arg(ap, int); //读取可变参数，第二个参数为可变参数的类型

    va_end(ap);          　　　　//清理工作，不调用会产生内存泄漏
    return sum;
}
```
