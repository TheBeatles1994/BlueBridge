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
void showList(ListNode* pHead)
{
    ListNode *temp = pHead;

    while(temp)
    {
        cout << temp->val<<" ";
        temp = temp->next;
    }

    cout<<endl;
}
/* 删除链表中重复的节点 */
/* 没有释放删除点的内存 */
ListNode* deleteDuplication(ListNode* pHead)
{
    if(pHead)
    {
        if(!pHead->next)
            return pHead;
    }
    else
        return NULL;

    //若开头有重复
    if(pHead->val == pHead->next->val)
    {
        ListNode *current = pHead;

        while(current->val == current->next->val)
        {
            current = current->next;
            if(!current->next)
                return NULL;
        }

        return deleteDuplication(current->next);
    }
    else
    {
        pHead->next = deleteDuplication(pHead->next);
        return pHead;
    }
}

int main(int argc, char *argv[])
{
    while(1)
    {
        createList();
        showList(deleteDuplication(pHead));
    }


    return 0;
}
