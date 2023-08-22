/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) 
{
    if(head == NULL || head->next == NULL)
        return false;
    struct ListNode* slow_p = head;
    struct ListNode* fast_p = head->next;
    while(slow_p != fast_p)
    {
        if(fast_p == NULL || fast_p->next == NULL)
            return false;
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
    }
    return true;
}