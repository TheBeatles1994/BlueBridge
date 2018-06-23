# 变长数组

```
Struct packet
{
    char data[2048];
}

Struct Buffer
{
    int len;
    char cData[0];
};
```
- 当发送1024个字节的数据时，第一个结构体会出现大量空间浪费，而第二个结构体有变长功能
```
char *tmp = (char*)malloc(sizeof(Buffer)+1024)
Buffer *p = (Buffer*)tmp;   //注意此处的强制转换！
p->len = 1024;
//通过p->cData定位到该部分的起始地址，最后，进行一个memcpy()内存拷贝，把要发送的数据填入到这段内存当中
memcpy(p.cData,"1024 datas............",1024);
```
- 长度为0的数组的主要用途是为了满足需要变长度的结构体。此处要考虑到数组中边界对齐要求，若data声明成void类型，则data可以转换成任意类型，且data中的成员类型都相同，这就满足了边界对齐，则不会出现内存碎片的问题，从而保证了数据包空间的连续性。