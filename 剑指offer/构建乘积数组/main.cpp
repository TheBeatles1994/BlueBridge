#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

vector<int> multiply(const vector<int>& A) {
    vector<int> B(A.size(), 1);

    for(size_t i=1;i<A.size();i++)
    {
        B[i] = B[i-1]*A[i-1];
    }

    int c=1;
    for(int i=A.size()-1-1;i>=0;i--)
    {
        B[i] *= (c = c*A[i+1]);
    }

    return B;
}

int main(int argc, char *argv[])
{
    vector<int> A = {1,2,3,4};
    vector<int> B = multiply(A);

    for(auto i:B)
        cout << i<<" ";

    return 0;
}
