#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

/* 二叉树中序排列的下一个节点 */
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
    /* 如果二叉树为空，则返回NULL */
    if(!pNode)
        return NULL;

    /* 如果二叉树存在右节点，返回右节点开始从左数第一个没有左节点的点 */
    if(pNode->right)
    {
        TreeLinkNode* node = pNode->right;
        while(node->left)
        {
            node = node->left;
        }
        return node;
    }

    /* 如果二叉树不存在右节点 */
    if(pNode->next == NULL)         //存在父节点（若为根节点）
    {
        return NULL;
    }
    if(pNode == pNode->next->left)  //当该节点是其父节点的左节点
    {
        return pNode->next;
    }
    else if(pNode == pNode->next->right)    //当该节点是其父节点的右节点
    {
        TreeLinkNode* node = pNode->next;   //找到该节点的父节点的父节点（先考虑左子树节点）
        while(node)
        {
            if(node->next == NULL)          //为根节点
            {
                return NULL;
            }
            if(node == node->next->left)
            {
                return node->next;
            }
            else if(node == node->next->right)
            {
                node = node->next;
            }
        }
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    return 0;
}
