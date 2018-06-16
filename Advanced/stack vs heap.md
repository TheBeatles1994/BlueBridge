difference|stack|heap
---|---|---
Store|Stored in computer RAM just like the heap.|Stored in computer RAM just like the stack.
scope|Variables created on the stack will go out of scope and are automatically deallocated.|In C++, variables on the heap must be destroyed manually and never fall out of scope. The data is freed with delete, delete[], or free.
Speed|Much faster to allocate in comparison to variables on the heap.|Slower to allocate in comparison to variables on the stack.
when to allocate|Implemented with an actual stack data structure.<br>Stores local data, return addresses, used for parameter passing.<br>Usually has a maximum size already determined when your program starts.|Used on demand to allocate a block of data for use by the program.
potential risk|Can have a stack overflow when too much of the stack is used (mostly from infinite or too deep recursion, very large allocations).|Can have fragmentation when there are a lot of allocations and deallocations.<br>Can have allocation failures if too big of a buffer is requested to be allocated.Responsible for memory leaks.
Pointer|Data created on the stack can be used without pointers.|In C++ or C, data created on the heap will be pointed to by pointers and allocated with new or malloc respectively.
when to use|You would use the stack if you know exactly how much data you need to allocate before compile time and it is not too big.|You would use the heap if you don't know exactly how much data you will need at run time or if you need to allocate a lot of data.


```
int foo()
{
  char *pBuffer; //<--nothing allocated yet (excluding the pointer itself, which is allocated here on the stack).
  bool b = true; // Allocated on the stack.
  if(b)
  {
    //Create 500 bytes on the stack
    char buffer[500];

    //Create 500 bytes on the heap
    pBuffer = new char[500];

   }//<-- buffer is deallocated here, pBuffer is not
}//<--- oops there's a memory leak, I should have called delete[] pBuffer;
```

另一方面的解释

## 堆
堆包含一个记录已使用块和空闲块的链表。新分配的块（通过new或malloc函数）可以通过从一个空闲块创建合适的块来满足。这需要更新堆上的链表。关于堆中块的元信息也常常存储在每个块前方的小区域中。

随着堆的增长，新块通常从较低地址分配到较高地址。因此，可以将堆看作一堆随存储器分配而增大的内存块。如果分配的堆太小，通常可以通过从底层操作系统获取更多内存来增加堆的大小。

分配和释放许多小块可能会使堆处在存在大量小空闲块的状态。由于没有空闲块足够大以满足分配请求，即使空闲块的组合大小可能足够大，分配大块的请求也可能失败。这被称为堆碎片。

当与空闲块相邻的使用块被free或delete时，新的空闲块可以与相邻的空闲块合并以创建更大的空闲块，从而有效地减少堆的碎片化。

## 栈

栈通常与CPU上名为栈指针的特殊寄存器紧密串联。最初栈指针指向栈的顶部（**堆栈中的最高地址**）。

CPU有特殊的指令将值压入栈（push）或将其从栈弹回（pop）。每次push都会将值存储（store）在栈指针的当前位置，并减少堆栈指针。一个pop弹回栈指针所指向的值（retrieve），然后增加堆栈指针（不要被添加一个值减少栈指针的事实所困惑，请记住堆栈增长到底端）。The values stored and retrieved are the values of the CPU registers.(没太懂)

当进入一个函数时，CPU将当前函数代码的入口地址存入到CPU栈中。 CPU然后通过将指令指针设置为所调用函数的地址跳转到该函数。稍后，当函数返回时，旧的指令指针将从栈中弹出，然后在调用该函数的代码中继续执行。

当进入一个函数时，栈指针会减少，（自动）为本地变量在堆栈上分配更多空间。如果函数有一个本地32位变量，则在堆栈上留出四个字节。当函数返回时，堆栈指针被移回以释放分配的区域。

如果函数具有参数，则在调用该函数之前将这些参数压入栈。 函数中的代码然后能够从当前栈指针从上导航堆栈以定位这些值。

每个新的函数调用都会分配函数参数，地址和存储局部变量的空间。


更多详细信息：

https://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap/80113#80113