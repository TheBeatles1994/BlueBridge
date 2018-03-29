#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    ListNode *node = pListHead;
    int length=0;

    while(node)
    {
        length++;
        node = node->next;
    }
    node = pListHead;
    int n=length-k;
    if(n<0)
        return NULL;
    else
    {
        while(n--)
            node = node->next;
        return node;
    }
}

int main(int argc, char *argv[])
{
    ListNode *headNode;
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
            headNode = inNode;
        }
        else
        {
            preNode->next = inNode;
        }
        preNode = inNode;
        inNode = preNode->next;
        cond++;
    }while(cond<=n);

    inNode = FindKthToTail(headNode, 4);
    cout <<inNode->val<<endl;

    return 0;
}

