/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode *cur = head, *pre = NULL;
    struct ListNode *tmp;
    bool sum_state = false;

    // 遍歷 list
        // 當前 node 非 0，下個 node 非 0: 把下個 node 的值加到當前 node 後，free 並且更新當前 node 的 next
        // 當前 node 非 0，下個 node 為 0: 移除下個 node
        // 當前 node 為 0，下個 node 不為 0: 移除當前 node
    while (cur && cur->next) {
        if (cur->val > 0) {
            if (cur->next->val == 0) {
                pre = cur->next;
                cur->next = cur->next->next;
                cur = cur->next;
                free(pre);
            } else {
                tmp = cur->next;

                cur->val += tmp->val;
                cur->next = tmp->next;
                
                free(tmp);
            }
        } else {
            if (pre == NULL)
                head = cur->next;
            else
                pre->next = cur->next;
            pre = cur;
            cur = cur->next;

            free(pre);
        }
    }

    return head;
}