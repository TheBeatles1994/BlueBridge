#include <endian.h>
 
// 短整型大小端互换
#define BigLittleSwap16(A)  ((((uint16_t)(A) & 0xff00) >> 8) | \
                            (((uint16_t)(A) & 0x00ff) << 8))
 // 长整型大小端互换
 
#define BigLittleSwap32(A)  ((((uint32_t)(A) & 0xff000000) >> 24) | \
                            (((uint32_t)(A) & 0x00ff0000) >> 8) | \
                            (((uint32_t)(A) & 0x0000ff00) << 8) | \
                            (((uint32_t)(A) & 0x000000ff) << 24))

 // 本机大端返回1，小端返回0
int checkCPUendian(void)
{
    union{
        uint32_t i;
        uint8_t  s[4];
    }c;

    c.i = 0x12345678;
    return (0x12 == c.s[0]);
}
 
// 模拟htonl函数，本机字节序转网络字节序
uint32_t htonl(uint32_t h)
{
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，转换成大端再返回
       return checkCPUendian() ? h : BigLittleSwap32(h);
}
 
// 模拟ntohl函数，网络字节序转本机字节序
uint32_t ntohl(uint32_t n)
{
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，网络数据转换成小端再返回
       return checkCPUendian() ? n : BigLittleSwap32(n);
}
 
// 模拟htons函数，本机字节序转网络字节序
uint16_t htons(uint16_t h)
{
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，转换成大端再返回
       return checkCPUendian() ? h : BigLittleSwap16(h);
}
 
// 模拟ntohs函数，网络字节序转本机字节序
uint16_t ntohs(uint16_t n)
{
       // 若本机为大端，与网络字节序同，直接返回
       // 若本机为小端，网络数据转换成小端再返回
       return checkCPUendian() ? n : BigLittleSwap16(n);
}
