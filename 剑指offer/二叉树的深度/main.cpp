#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};
int maxLength=0;

void EnterChildTree(TreeNode* node, int tempLen)
{
    if(!node)
    {
        if(tempLen>maxLength)
            maxLength = tempLen;
        return;
    }

    EnterChildTree(node->left, tempLen+1);
    EnterChildTree(node->right, tempLen+1);

    return;
}

int TreeDepth(TreeNode* pRoot)
{
    EnterChildTree(pRoot, 0);
    return maxLength;
}

