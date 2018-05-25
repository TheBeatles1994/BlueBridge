#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

bool compTree(TreeNode* leftNode, TreeNode* rightNode)
{
    if(leftNode == NULL)
        return (rightNode == NULL);
    if(rightNode == NULL)
        return false;
    if(leftNode->val == rightNode->val)
        return compTree(leftNode->left, rightNode->right)&&compTree(leftNode->right, rightNode->left);
    else
        return false;
}

bool isSymmetrical(TreeNode* pRoot)
{
    if(!pRoot)
        return true;

    return compTree(pRoot->left, pRoot->right);
}

int main()
{
    return 0;
}
