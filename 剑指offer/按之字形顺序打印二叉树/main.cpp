#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

vector<vector<int> > Print(TreeNode* pRoot) {

    vector<vector<int> > vvRst;
    vector<int> vRst;

    if(!pRoot)
        return vvRst;

    stack<TreeNode*> vecTree[2];    //0指奇数行，1指偶数行
    int index=0;
    int next =1;

    vecTree[index].push(pRoot);

    while(!vecTree[index].empty())
    {
        TreeNode* node = vecTree[index].top();
        vecTree[index].pop();
        vRst.push_back(node->val);

        if(index == 0)              //奇数行，下一行为偶数行
        {
            if(node->left)
                vecTree[next].push(node->left);
            if(node->right)
                vecTree[next].push(node->right);
        }
        else                        //偶数行，下一行为奇数行
        {
            if(node->right)
                vecTree[next].push(node->right);
            if(node->left)
                vecTree[next].push(node->left);
        }

        if(vecTree[index].empty())
        {
            index = 1-index;
            next = 1-next;
            vvRst.push_back(vRst);
            vRst.clear();
        }
    }

    return vvRst;
}

int main()
{
    return 0;
}
