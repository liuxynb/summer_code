/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法一：新建一个链表利用头插法进行反转
// struct ListNode* reverseList(struct ListNode* head)
// {
//     struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
//     L->next = NULL;
//     while(head != NULL)
//     {
//         struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
//         s->val = head->val;
//         s->next = L->next;
//         L->next = s;
//         head = head->next;
//     }
//     return L->next;
// }

//方法二：采用双指针法进行翻转，不需要重新分配空间
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    while(curr != NULL)
    {
        struct ListNode* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}