#include <iostream>
#include <vector>
#include <queue>

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

    queue<TreeNode*> vecTree[2];    //还是需要两个，一个保存当前行，一个保存下一行
    int index=0;
    int next =1;

    vecTree[index].push(pRoot);

    while(!vecTree[index].empty())
    {
        TreeNode* node = vecTree[index].back();
        vecTree[index].pop();
        vRst.push_back(node->val);

        if(node[index]->left)
            vecTree[next].push(node->left);
        if(node[index]->right)
            vecTree[next].push(node->right);

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
