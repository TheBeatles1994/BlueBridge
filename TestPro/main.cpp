#include <iostream>
#include <bitset>
#include <iomanip>
#include <math.h>
//#include <windows.h>
using namespace std;

struct box_props
{
     unsigned int opaque       : 1;
     unsigned int fill_color   : 3;
     unsigned int              : 4; // fill to 8 bits
     unsigned int show_border  : 1;
     unsigned int border_color : 3;
     unsigned int border_style : 2;
     unsigned char             : 0; // fill to nearest byte (16 bits)
     unsigned char width       : 4, // Split a byte into 2 fields of 4 bits
                   height      : 4;
};
struct S1 {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 2 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    // 3 bits: unused
    unsigned char b1 : 3, : 2, b2 : 6, b3 : 2;
};
struct S2 {
 // three-bit unsigned field,
 // allowed values are 0...7
 unsigned char b : 6;
};

struct S3
{
    unsigned int a : 1;
    unsigned int   : 2;/*该2位不能使用*/
    unsigned int b : 3;
    unsigned int c  :2;
};

int main()
{
    //cout << sizeof(struct S)<<endl;

    //struct S3 s;
//    while(1)
//    {
//        ++s.b;
//        std::cout << (int)s.b << '\n'; // output: 0
//        Sleep(10);
//    }
    //cout<<sizeof(s)<<endl;
    int num;
    while(cin>>num)
    {
        cout<<num*2<<endl;
        if(num == 5)
            break;
    }

    return 4;
}

