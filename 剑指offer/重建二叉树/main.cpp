#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>

using namespace std;
#define MAXLEN 100

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 * Function:
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * pre是前序，即中左右
 * vin是中序，即左中右
 */
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size()==0)
        return NULL;

    int mid = pre[0];   //中间节点的值
    int midNumber;      //中间节i点在中序排列中的序号

    TreeNode* head = new TreeNode(mid);

    for(int i=0;i<vin.size();i++)
    {
        if(vin[i] == mid)
        {
            midNumber = i;
            break;
        }
    }

    vector<int> pre_left,pre_right,vin_left,vin_right;
    for(int i=0;i<midNumber;i++)
    {
        vin_left.push_back(vin[i]);
        pre_left.push_back(pre[1+i]);
    }
    for(int i=midNumber+1;i<vin.size();i++)
    {
        vin_right.push_back(vin[i]);
        pre_right.push_back(pre[i]);
    }

    head->left = reConstructBinaryTree(pre_left,vin_left);
    head->right = reConstructBinaryTree(pre_right,vin_right);

    return head;
}
/*
 * Function:
 * 后序排列 左右中
 */
void printTreeNodeInPost(TreeNode* node)
{
    if(!node)
        return;

    printTreeNodeInPost(node->left);
    printTreeNodeInPost(node->right);
    cout <<node->val;
}

int main(int argc, char *argv[])
{
    int N;
    int n;

    cin >>N;
    vector<int> pre,vin;
    //前序输入
    for(int i=0;i<N;i++)
    {
        cin>>n;
        pre.push_back(n);
    }
    //中序输入
    for(int i=0;i<N;i++)
    {
        cin>>n;
        vin.push_back(n);
    }

    TreeNode* head = reConstructBinaryTree(pre,vin);
    printTreeNodeInPost(head);
    return 0;
}
