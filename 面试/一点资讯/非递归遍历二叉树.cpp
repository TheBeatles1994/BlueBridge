#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

struct CtTree{
    TreeNode *node;
    bool first;
    CtTree():node(NULL),first(true){}
};

using namespace std;

vector<int> rst;
/*
中序非递归遍历二叉树
备注：
*/
void InOrderTraverse(TreeNode* tree)
{
    stack<TreeNode*> stackT;

    while(true)
    {
        while(tree->left)
        {
            stackT.push(tree);
            tree = tree->left;
        }
        rst.push_back(tree->val);

        while(true)
        {
            if(tree->right)
            {
                tree = tree->right;
                break;
            }
            else
            {
                if(stackT.empty())
                    return;
                tree = stackT.top();
                stackT.pop();
                rst.push_back(tree->val);
            }
        }
    }
}
/*
后序非递归遍历二叉树
备注：
必须要有一个数据结构，其中记录是否已经访问过左和右节点
*/
void PostOrderTraverse(TreeNode* tree)
{
    stack<CtTree *> mystack;

    if(!tree)
        return;

    do{
        while(tree->left)
        {
            CtTree *node = new CtTree;
            node->node = tree;
            mystack.push(node);
            tree = tree->left;
        }
        while(tree->right)
        {
            CtTree *node = new CtTree;
            node->node = tree;
            node->first = false;
            mystack.push(node);
            tree = tree->right;
        }
        CtTree *temp;
        do
        {
            rst.push_back(tree->val);
            if(mystack.empty())
                return;
            temp = mystack.top();
            mystack.pop();
            tree = temp->node;
        }while(!temp->first);
        if(temp->first)
        {
            temp->first = false;
            mystack.push(temp);
            tree = tree->right;
        }
    }while(true);
}

int main()
{
    TreeNode tree[9]={0,1,2,3,4,5,6,7,8};
    tree[0].val = 0;
    tree[1].val = 1;
    tree[2].val = 2;
    tree[3].val = 3;
    tree[4].val = 4;
    tree[5].val = 5;
    tree[6].val = 6;
    tree[7].val = 7;
    tree[8].val = 8;

    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];
    tree[2].left = &tree[5];
    tree[2].right = &tree[6];
    tree[4].left = &tree[7];
    tree[4].right = &tree[8];

    PostOrderTraverse(tree);
    for(auto i:rst)
        cout<<i<<" ";
    return 0;
}
