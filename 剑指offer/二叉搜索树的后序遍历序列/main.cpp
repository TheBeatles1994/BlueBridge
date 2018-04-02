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

    postOrderTraverse(node->left);
    postOrderTraverse(node->right);
    cout << node->val <<" ";
}
/*
 * 函数功能：
 * 判断该数组是不是某二叉搜索树的后序遍历
 * 后序遍历 left right mid
 */
bool recurFunc(vector<int> sequence, int start, int end)
{
    if(start>=end)
        return true;

    int mid = sequence[end];
    int midOrder=-1;
    /* 划分左右区域 */
    for(int i=start;i<end;i++)
    {
        if(sequence[i]>=mid)
        {
            midOrder = i;
        }
        if(midOrder!=-1 && sequence[i]<mid)
            return false;
    }
    if(midOrder == -1)
        midOrder = end;

    bool rst;
    rst = recurFunc(sequence, start, midOrder-1) && recurFunc(sequence, midOrder, end-1);
    return rst;
}
bool VerifySquenceOfBST(vector<int> sequence) {
    if(sequence.empty())
        return false;

    bool rst;
    rst = recurFunc(sequence, 0, sequence.size()-1);                    //左边序列
    return rst;

}
int main(int argc, char *argv[])
{
    vector<int> data={0,1,3,2,6,8,7,9,5,4};
#if 0
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
#else
    if(VerifySquenceOfBST(data))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
#endif

    return 0;
}

