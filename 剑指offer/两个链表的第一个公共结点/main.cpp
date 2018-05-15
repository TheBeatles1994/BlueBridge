struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if(pHead1==nullptr || pHead2==nullptr)
        return nullptr;

    ListNode *start = pHead1;       //每次temp与start来比
    ListNode *temp = pHead2;        //每次temp向后移动

    while(temp)    //start非空
    {
        while(start)
        {
            if(temp == start)
                return temp;
            else
            {
                start = start->next;
            }
        }
        start = pHead1;
        temp = temp->next;
    }

    return nullptr;
}

