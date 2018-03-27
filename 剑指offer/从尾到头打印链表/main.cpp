#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>

using namespace std;
#define MAXLEN 100

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};
/*
 * Function:
 * 输入一个链表，从尾到头打印链表每个节点的值。
 */
vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> vecHead;
    //vector<int> vecTail;
    do
    {
        vecHead.push_back(head->val);
    }while(head = head->next);

//    for(int i=0;i<vecHead.size();i++)
//    {
//        vecTail.push_back(vecHead[vecHead.size()-1-i]);
//    }
    reverse(vecHead.begin(),vecHead.end());
    return vecHead;
}

int main(int argc, char *argv[])
{
    int N;
    ListNode *head = NULL;
    ListNode *nodeBefore, *nodeAfter;

    cin >>N;
    int n;
    cin >>n;
    nodeBefore = new ListNode(n);
    head = nodeBefore;
    for(int i=1;i<N;i++)
    {
        cin >> n;
        nodeAfter = new ListNode(n);
        nodeBefore->next = nodeAfter;
        nodeBefore = nodeAfter;
        nodeAfter = nodeBefore->next;
    }

    vector<int> vint = printListFromTailToHead(head);
    for(vector<int>::iterator it=vint.begin();it!=vint.end();it++)
    {
        cout << *it;
    }

    cout <<endl;

    return 0;
}
