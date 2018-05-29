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

int deepTree(TreeNode *node)
{
    if(!node)
        return 0;
    //下面这一段注释了就是对的。。。。搞不懂
//    if(node->left)
//    {
//        if(node->left->val > node->val)
//            return -1;
//    }
//    if(node->right)
//    {
//        if(node->right->val < node->val)
//            return -1;
//    }

    int deepL = deepTree(node->left);
    int deepR = deepTree(node->right);

    if(deepL == -1 || deepR == -1)
        return -1;

    if(abs(deepL-deepR)<=1)
        return (deepL>deepR ? deepL+1:deepR+1);
    else
        return -1;
}

bool IsBalanced_Solution(TreeNode* pRoot)
{
    if(!pRoot)
        return true;

    int isTree = deepTree(pRoot);

    if(isTree != -1)
        return true;
    else
        return false;
}

int main()
{
    return 0;
}
