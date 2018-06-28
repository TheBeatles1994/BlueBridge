# _stdcall
1. 参数采用从右到左的压栈方式，被调函数自身在返回前清空堆栈。
2. **被调函数自身在返回前清空堆栈。**
3. WIN32 Api都采用_stdcall调用方式，这样的宏定义说明了问题：#define WINAPI _stdcall
4. 按C编译方式，_stdcall调用约定在输出函数名前面加下划线，后面加“@”符号和参数的字节数，形如_functionname@number.故int func( int a, double b )会被解释成_func@12.
# _cdecl
1. _cdecl是C/C++的缺省调用方式
2. 参数采用从右到左的压栈方式，由调用者完成压栈操作
3. **传送参数的内存栈由调用者维护**
4. _cedcl约定的函数只能被C/C++调用
5. 每一个调用它的函数都包含清空堆栈的代码，所以产生的可执行文件大小会比调用_stdcall函数的大。
6. 按C编译方式，_cdecl调用约定仅在输出函数名前面加下划线，形如_functionname