/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode dummy; // 创建一个虚拟节点作为新的头节点
    dummy.next = head;
    struct ListNode* current = &dummy;

    while (current->next != NULL && current->next->next != NULL) {
        struct ListNode* first = current->next;
        struct ListNode* second = current->next->next;

        // 交换节点的值而不是指针
        first->next = second->next;
        second->next = first;
        current->next = second;

        current = first; // 移动 current 到已经交换的节点的下一个位置
    }

    return dummy.next; // 返回新的头节点
}
