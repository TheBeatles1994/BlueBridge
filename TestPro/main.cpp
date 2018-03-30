#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{

}

int main(int argc, char *argv[])
{
    ListNode *headNode1,*headNode2;
    ListNode *inNode, *preNode;
    int n, cond;
    cond = 1;

    cin>>n;
    do
    {
        int in;
        cin >>in;
        inNode = new ListNode(in);
        if(cond == 1)
        {
            headNode1 = inNode;
        }
        else
        {
            preNode->next = inNode;
        }
        preNode = inNode;
        inNode = preNode->next;
        cond++;
    }while(cond<=n);

    cond = 1;
    cin>>n;
    do
    {
        int in;
        cin >>in;
        inNode = new ListNode(in);
        if(cond == 1)
        {
            headNode2 = inNode;
        }
        else
        {
            preNode->next = inNode;
        }
        preNode = inNode;
        inNode = preNode->next;
        cond++;
    }while(cond<=n);

    //inNode = Merge(headNode1, headNode2);
    inNode = Merge(headNode1, NULL);
    while(inNode)
    {
        cout << inNode->val<<" ";
        inNode = inNode->next;
    }

    return 0;
}

