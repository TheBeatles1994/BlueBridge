#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
/*
 * 二叉搜索树定义
 */
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
}TreeNode, *pTreeNode;

TreeNode *preNode;
TreeNode *headNode = NULL;
/*
 * 函数功能：
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
 */
TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(!pRootOfTree)
        return NULL;

    Convert(pRootOfTree->left);
    if(!headNode)
    {
        headNode = pRootOfTree;
        preNode = headNode;
    }
    else
    {
        preNode->right = pRootOfTree;
        pRootOfTree->left = preNode;
        preNode = pRootOfTree;
    }
    Convert(pRootOfTree->right);

    return headNode;
}
/*
 * 函数功能：
 * 创建二叉搜索树
 */
void createNode(pTreeNode &node, int n)
{
    TreeNode *temp = new TreeNode(n);
    if(!node)
        node = temp;
    else
    {
        if(n<node->val)
            createNode(node->left, n);
        else if(n>node->val)
            createNode(node->right, n);
        else
            delete temp;
    }
}
/*
 * 函数功能：
 * 判断生成的双向链表对不对
 */
void judgeDoubleList(TreeNode *node)
{
    if(!node)
        return;

    //正向打印所有值
    while(1)
    {
        cout<<node->val<<" ";
        if(node->right)
            node = node->right;
        else
            break;
    }
    cout<<endl;
    //逆向打印所有值
    while(1)
    {
        cout<<node->val<<" ";
        if(node->left)
            node = node->left;
        else
            break;
    }
}
int main(int argc, char *argv[])
{
    vector<int> data={3,2,7,5,9,4,1,8,6};
    TreeNode *head = NULL;
    for(int i=0;i<data.size();i++)
    {
        createNode(head, data[i]);
    }
    TreeNode *temp = Convert(head);

    judgeDoubleList(temp);

    return 0;
}

