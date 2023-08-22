/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool solve(struct ListNode** head, struct ListNode* tail)
{
    if(tail == NULL)
        return true;
    bool flag = solve(head, tail->next);
    if(flag == false)
        return false;
    if(tail->val != (*head)->val)
        return false;
    (*head) = (*head)->next;
    return flag;
}
//使用&head是为了全局化修改head
bool isPalindrome(struct ListNode* head)
{
    return solve(&head, head);
}