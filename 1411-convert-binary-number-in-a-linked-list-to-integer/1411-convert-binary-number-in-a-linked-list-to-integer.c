/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int getDecimalValue(struct ListNode* head) {
    int ret = 0;

    while (head != NULL) {
        ret = (ret << 1) | head->val;
        head = head->next;
    }

    return ret;
}