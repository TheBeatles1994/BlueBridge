#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
ListNode *pHead;
ListNode *pCur;
ListNode *pNew;
/* 练习用：创建表 */
void createList()
{
    bool isHead=true;

    int n;
    while(cin>>n)
    {
        if(n!=-1)
        {
            pNew = new ListNode(n);
            if(isHead)
            {
                pHead = pNew;
                pCur = pNew;
                isHead = false;
            }
            else
            {
                pCur->next = pNew;
                pCur = pNew;
            }
        }
        else
            break;
    }
}
/* 练习用：输出链表 */
void showList()
{
    ListNode *temp = pHead;

    while(temp)
    {
        cout << temp->val<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(!pHead)
        return NULL;

    ListNode *fast = pHead->next->next;
    ListNode *slow = pHead->next;

    while(fast != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow = pHead;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main(int argc, char *argv[])
{
    createList();

    showList();

    return 0;
}
