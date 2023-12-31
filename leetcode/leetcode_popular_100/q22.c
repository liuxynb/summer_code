/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode* p = headA;
    struct ListNode* q = headB;
    while(p != q)
    {
        p = p!=NULL?p->next:headB;
        q = q!=NULL?q->next:headA;
        if(p == q && q == NULL)
            break;
    }
    return p;
}