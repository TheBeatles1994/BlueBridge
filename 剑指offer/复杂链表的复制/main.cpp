/*
 * 学习搜索二叉树BST
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
/*
 * 复杂链表定义
 */
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};
/*
 * 函数功能：
 * 打印整个顺序列表
 */
void printList(RandomListNode* pHead)
{
    if(!pHead)
        return;

    cout<<pHead->label<<" ";
    printList(pHead->next);
}
/*
 * 函数功能：
 * 复制后复杂链表
 */
RandomListNode* Clone(RandomListNode* pHead)
{
    if(!pHead)
        return NULL;

    RandomListNode* node = pHead;       //保存原指针的头结点
    RandomListNode *myHead, *tempNode;
    myHead = NULL;
    //复制原链表，没有对ramdom进行操作
    while(node)
    {
        RandomListNode* temp = new RandomListNode(node->label);
        if(!myHead)
        {
            myHead = temp;
            tempNode = myHead;
        }
        else
        {
            tempNode->next = temp;
            tempNode = temp;
        }
        node = node->next;
    }
    node = pHead;
    tempNode = myHead;
    while(node)
    {
        if(node->random)
        {
            RandomListNode *countRandom = pHead;
            int count = 0;  //标记node->random在链表中的位置，0表示head
            while(countRandom != node->random)
            {
                count++;
                countRandom = countRandom->next;
            }
            countRandom = myHead;
            while(count--)
            {
                countRandom = countRandom->next;
            }
            tempNode->random = countRandom;
        }

        node = node->next;
        tempNode = tempNode->next;
    }

    return myHead;
}

int main(int argc, char *argv[])
{
    vector<int> data={10,5,12,4,7,8};
    RandomListNode *head = NULL;
    RandomListNode *front, *back;
    RandomListNode *copyHead;

    front = head;
    for(int i=0;i<data.size();i++)
    {
        if(i==0)
        {
            head = new RandomListNode(data[i]);
            front = head;
        }
        else
        {
            back = new RandomListNode(data[i]);
            front->next = back;
            front = back;
        }
    }

    copyHead = Clone(head);

    printList(copyHead);

    return 0;
}

