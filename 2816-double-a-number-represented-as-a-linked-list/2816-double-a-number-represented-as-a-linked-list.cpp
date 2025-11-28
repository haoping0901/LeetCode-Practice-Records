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
    ListNode* doubleIt(ListNode* head) {
        // Reverse
        // double val and reverse again
        ListNode *cur = head, *pre = nullptr, *next;
        int carry = 0;

        while (cur != nullptr) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        cur = pre;
        pre = nullptr;

        while (cur != nullptr) {
            cur->val = (cur->val << 1) + carry;
            carry = cur->val / 10;
            cur->val %= 10;

            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if (carry > 0) {
            cur = new ListNode;
            cur->val = carry;
            cur->next = head;
            head = cur;
        }

        return head;
    }
};