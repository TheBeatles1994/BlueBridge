# 结构体边界对齐

## 当结构体中只有一个变量时
1. 此时是多少就是多少
```
struct test{
    char data;
};
//上面sizeof为1
```
## 当结构体中有相同变量时
1. 是多少就是多少
```
struct test{
    char data1;
    char data2;
};
//上面sizeof为2
```
## 当结构体中有不同变量时
```
struct test
{
    char data;
    short data1;
    char data2;
};
//sizeof为6！   
struct test
{
    char data;
    int data1;
    char data2;
};
//sizeof为12
struct test
{
    char data;
    double data1;
    char data2;
};
//sizeof为24
```
## 偏移量概念
1. 为了提高CPU的存储速度，VC对一些变量的起始地址做了”对齐”处理。在默认情况下，VC规定各成员变量存放的起始地址相对于结构的起始地址的偏移量必须为该变量的类型所占用的字节数的倍数。

类型|对齐方式（变量存放的起始地址相对于结构的起始地址的偏移量）
---|---
char|偏移量必须为sizeof(char)即1的倍数
int|     偏移量必须为sizeof(int)即4的倍数
float |  偏移量必须为sizeof(float)即4的倍数
double | 偏移量必须为sizeof(double)即8的倍数
short  | 偏移量必须为sizeof(short)即2的倍数
## 两个特例（易错）说明
```
struct test
{
    double dda1;
    char dda;
    int type;
};
//sizeof为16
/* 为上面的结构分配空间的时候，VC根据成员变量出现的顺序和对齐方式，先为第一个成员dda1分配空间，其起始地址跟结构的起始地址相同（偏移量0刚好为sizeof(double)的倍数），该成员变量占用sizeof(double)=8个字节；接下来为第二个成员dda分配空间，这时下一个可以分配的地址对于结构的起始地址的偏移量为8，是sizeof(char)的倍数，所以把dda存放在偏移量为8的地方满足对齐方式，该成员变量占用 sizeof(char)=1个字节；接下来为第三个成员type分配空间，这时下一个可以分配的地址对于结构的起始地址的偏移量为9（8+1），不是sizeof(int)=4的倍数，为了满足对齐方式对偏移量的约束问题，VC自动填充3个字节（这三个字节没有放什么东西），这时下一个可以分配的地址对于结构的起 始地址的偏移量为12（8+1+3），刚好是sizeof(int)=4的倍数，所以把type存放在偏移量为12的地方，该成员变量占sizeof(int)=4个 字节；这时整个结构的成员变量已经都分配了空间，总的占用的空间大小为：8+1+3+4=16，刚好为结构的字节边界数（即结构中占用最大空间的类型所占用的字节sizeof(double)=8）的倍数，所以没有空缺的字节需要填充。所以整个结构的大小为：sizeof(MyStruct)=8+1+3+4=16，其中有3个字节是VC自动填充的，没有放任何有意义的东西。 */
``` 
```
struct test
{
    char dda;
    double dda1;
    int type;
};
//sizeof为24
/* 所有成员变量都分配了空间，空间总的大小为1+7+8+4=20，不是结构的节边界数（即结构中占用最大空间的类型所占用的字节数sizeof (double)=8）的倍数，所以需要填充4个字节，以满足结构的大小为sizeof(double)=8的倍数。*/
```


