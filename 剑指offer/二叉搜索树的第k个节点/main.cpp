#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

TreeNode* kNode=NULL;

void midSearchTraverse(TreeNode *node, int &count, int k)
{
    if(!node)
        return;

    midSearchTraverse(node->left, count, k);
    count++;
    if(count == k)
    {
        kNode = node;
    }
    midSearchTraverse(node->right, count, k);
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    int count=0;

    midSearchTraverse(pRoot, count, k);

    return kNode;
}

int main()
{
    return 0;
}
