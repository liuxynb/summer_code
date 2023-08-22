/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            struct ListNode* index = fast;
            struct ListNode* p = head;
            while(index != p)
            {
                p = p->next;
                index = index->next;
            }
            return index;
        }
    }
    return NULL;
}