/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode *fast=head, **ptr = &head;

    while (fast && fast->next) {
        fast = fast->next->next;
        ptr = &(*ptr)->next;
    }
    (*ptr) = (*ptr)->next;

    return head;
}