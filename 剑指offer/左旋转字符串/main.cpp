#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string LeftRotateString(string str, int n) {
    if(str.size() == 0)
        return string("");

    n = n%str.size();

    string rst1(str, n);
    string rst2(str, 0, n);

    return rst1+rst2;
}

int main(int argc, char *argv[])
{
    string str("abcXYZdef");

    cout << LeftRotateString(str, 3)<<endl;

    return 0;
}
