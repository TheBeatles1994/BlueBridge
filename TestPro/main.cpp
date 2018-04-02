/*
 * 学习搜索二叉树BST
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
/*
 * BST定义
 */
typedef struct BSTnode
{
    BSTnode *left;
    BSTnode *right;
    int val;
    BSTnode(int n):val(n), left(NULL),right(NULL){}
}BST, *pBST;
/*
 * 函数功能：
 * 构造BST
 * 注意指针的引用！！！
 */
void insertNode(pBST &node, int n)
{
    if(!node)
    {
        node = new BSTnode(n);
    }
    else
    {
        if(n<node->val)
        {
            insertNode(node->left, n);
        }
        else
        {
            insertNode(node->right, n);
        }
    }
}
/*
 * 函数功能：
 * 中序遍历 left mid right
 */
void inOrderTraverse(BST *node)
{
    if(!node)
        return;

    inOrderTraverse(node->left);
    cout << node->val <<" ";
    inOrderTraverse(node->right);
}
/*
 * 函数功能：
 * 前序遍历 mid left right
 */
void preOrderTraverse(BST *node)
{
    if(!node)
        return;

    cout << node->val <<" ";
    preOrderTraverse(node->left);
    preOrderTraverse(node->right);
}
/*
 * 函数功能：
 * 后序遍历 left right mid
 */
void postOrderTraverse(BST *node)
{
    if(!node)
        return;

    postOrderTraverse(node->right);
    postOrderTraverse(node->left);
    cout << node->val <<" ";
}
/*
 * 函数功能：
 * 判断该数组是不是某二叉搜索树的后序遍历
 * 后序遍历 left right mid
 */
bool recurFunc(vector<int> sequence, int start, int end)
{

}
bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.empty())
        return false;

    int mid = sequence[sequence.size()-1];
    int midOrder;
    /* 找到根节点的序号 */
    for(int i=0;i<sequence.size();i++)
    {
        if(sequence[i]>=mid)
        {
            midOrder = i;
            break;
        }
    }

    bool rst=true;
    rst = rst && recurFunc(sequence, 0, midOrder-1);                    //左边序列
    rst = rst && recurFunc(sequence, midOrder, sequence.size()-1-1);    //右边序列(除去根节点)
    return rst;

}
int main(int argc, char *argv[])
{
    vector<int> data={4, 5, 2, 1, 0, 9, 3, 7, 6, 8, 4};
    BST *node = NULL;

    for(int i=0;i<data.size();i++)
    {
        insertNode(node, data[i]);
    }
    cout<<"inOrderTraverse:"<<endl;
    inOrderTraverse(node);
    cout<<endl;
    cout<<"preOrderTraverse:"<<endl;
    preOrderTraverse(node);
    cout<<endl;
    cout<<"postOrderTraverse:"<<endl;
    postOrderTraverse(node);
    cout<<endl;

    return 0;
}

