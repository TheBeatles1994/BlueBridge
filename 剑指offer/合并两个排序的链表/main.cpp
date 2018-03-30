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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if(!(pHead1 || pHead2))         //两指针同时为空
        return NULL;

    ListNode *p1 = pHead1;          //指向pHead1的指针
    ListNode *p2 = pHead2;          //指向pHead2的指针
    ListNode *rstNode, *tempNode, *tempPreNode;
    bool headFlag = true;
    int minValue;

    while(p1 || p2)
    {
        if(p1&&p2)                          //两指针同时不为null
        {
            if(p1->val<=p2->val)
            {
                minValue = p1->val;
                p1 = p1->next;
            }
            else
            {
                minValue = p2->val;
                p2 = p2->next;
            }

            tempNode = new ListNode(minValue);
            if(headFlag)                    //第一次
            {
                rstNode = tempNode;         //头指针
                tempPreNode = tempNode;
                headFlag = false;
            }
            else
            {
                tempPreNode->next = tempNode;
                tempPreNode = tempNode;
            }
        }
        else if(p1)
        {
            if(headFlag)                    //第一次
            {
                rstNode = p1;
            }
            else
            {
                tempPreNode->next = p1;
            }
            p1=NULL;
        }
        else if(p2)
        {
            if(headFlag)                    //第一次
            {
                rstNode = p2;
            }
            else
            {
                tempPreNode->next = p2;
            }
            p2=NULL;
        }
        else
        {
            tempPreNode->next = NULL;
        }
    }

    return rstNode;
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

