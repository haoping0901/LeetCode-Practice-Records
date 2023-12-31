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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *prefix = new ListNode(0, head);
        ListNode *pre = prefix, *cur = head, *peak = head->next;

        while (peak) {
            int val = cur->val;
            if (peak->val == cur->val) {
                while (peak && peak->val == val) peak = peak->next;
                pre->next = peak;
            } else {
                pre = cur;
            }
            cur = peak;
            if (peak) peak = peak->next;
        }

        return prefix->next;
    }
};