#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* ReverseList(ListNode* pHead) {
    ListNode *node = pHead;
    ListNode *tempNode;
    int length=0;
    stack<int> sData;

    while(node)
    {
        length++;
        sData.push(node->val);
        node = node->next;
    }
    node = pHead;                   //node指向第一个指针
    while(node)
    {
        node->val = sData.top();
        sData.pop();
        node = node->next;
    }

    return pHead;
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

    inNode = ReverseList(headNode);
    while(inNode)
    {
        cout << inNode->val<<" ";
        inNode = inNode->next;
    }

    return 0;
}

