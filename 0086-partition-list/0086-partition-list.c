/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// #define BT(a, b) (a) > (b) ? (a) : (b)

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode **lt_nodes = &head, *be_head, **be_nodes = &be_head;

    for (struct ListNode *cur=head; cur != NULL; cur=cur->next) {
        if (cur->val >= x) {
            *be_nodes = cur;
            be_nodes = &(*be_nodes)->next;
        } else {
            *lt_nodes = cur;
            lt_nodes = &(*lt_nodes)->next;
        }
    }
    *be_nodes = NULL;
    *lt_nodes = be_head;

    return head;
}