/*
 * 学习搜索二叉树BST
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
/*
 * 二叉树定义
 */
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
}BSTnode, *PBSTnode;
/* 全局变量定义，用于递归函数记录 */
vector<int> vecData;
vector<vector<int> > vvecData;

/*
 * 函数功能：
 * 构造搜索二叉树
 */
void createBST(PBSTnode &node, int n)
{
    if(!node)
    {
        node = new BSTnode(n);
    }
    else
    {
        if(n<node->val)
        {
            createBST(node->left, n);
        }
        else if(n>node->val)
        {
            createBST(node->right, n);
        }
    }
}
/*
 * 函数功能：
 * 中序排列，用来测试构造的二叉树对不对
 */
void midOrderTraverse(BSTnode *node)
{
    if(!node)
        return;
    midOrderTraverse(node->left);
    cout<<node->val<<" ";
    midOrderTraverse(node->right);
}
/*
 * 函数功能：
 * 二叉树中和为某一值的路径
 */
void recurFunc(TreeNode *node, int n)
{
    if(!node && n!=0)   //到达节点低端，且和不为expect值
    {
        return;
    }
    else
    {
        vecData.push_back(node->val);

        if(!(node->left || node->right))    //判断已到达叶节点
        {
            if(n-node->val == 0)
            {
                vvecData.push_back(vecData);
            }
        }
        else
        {
            recurFunc(node->left, n-node->val);
            recurFunc(node->right, n-node->val);
        }

        vecData.pop_back();
    }
}
vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    if(!root)
        return vvecData;
    recurFunc(root, expectNumber);
    return vvecData;
}
int main(int argc, char *argv[])
{
    vector<int> data={10,5,12,4,7};
    BSTnode *root = NULL;
    int expect;

    for(auto i:data)
    {
        createBST(root, i);
    }

    //midOrderTraverse(root);
    cin>>expect;
    vector<vector<int> >vvPrint = FindPath(root, expect);
    for(int i=0;i<vvPrint.size();i++)
    {
        for(int j=0;j<vvPrint[i].size();j++)
        {
            cout<<vvPrint[i][j]<<" ";
        }
        cout <<endl;
    }

    return 0;
}

