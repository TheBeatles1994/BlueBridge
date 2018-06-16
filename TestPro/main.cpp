#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<stdlib.h>

using namespace std;
#define MAXLEN 100
/*
 * Function:
 *
 */
void test(char *&ch)
{
    *ch = 'y';
}

int main(int argc, char *argv[])
{
    char *ch = new char('n');

    test(ch);
    printf("%c", *ch);

    return 0;
}
