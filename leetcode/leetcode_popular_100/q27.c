/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//采用快慢指针的方法
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* quick = head;
    struct ListNode* slow = head;
    int i;
    for (i = 0; i <= n && quick; i++)
    {
        quick = quick->next;
    }
    if(i<=n)
    {
        struct ListNode* p = head;
        head = head->next;
        free(p);  
        return head;
    }
    while(quick)
    {
        slow = slow->next;
        quick = quick->next;
    }
    struct ListNode* p = slow->next;
    slow->next = slow->next->next;
    free(p);
    return head;
}