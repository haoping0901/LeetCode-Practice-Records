/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        // Check next group size (group_size)
        // group_size is odd: do nothing
        // even: reverse

        ListNode *next_head, *pre_tail, *pre, *cur, *next, *cur_head, *tmp;
        int target_size = 1, cur_size, i;

        next_head = pre_tail = pre = cur = next = head;
        while (cur) {
            // Check current group size
            for (cur_size = 0; cur_size < target_size && next_head; ++cur_size)
                next_head = next_head->next;

            // Reverse group if size is even
            if (!(cur_size & 0x1)) {
                pre_tail = pre;
                pre = next_head;
                cur_head = cur;
                for (i = 0; i < cur_size; ++i) {
                    next = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = next;
                }
                pre_tail->next = pre;
                pre_tail = cur_head;
                pre = pre_tail;
            } else {
                pre = cur;
                for (i = 0; i < cur_size - 1; ++i)
                    pre = pre->next;
            }

            cur = next_head;
            ++target_size;
        }

        return head;
    }
};