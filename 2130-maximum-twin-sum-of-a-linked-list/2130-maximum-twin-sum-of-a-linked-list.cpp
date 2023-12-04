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
    int pairSum(ListNode* head) {
        ListNode *slow=head, *fast=head->next;
        int max=0;

        // find the node in the middle 
        while (fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *pre=nullptr, *cur=slow->next, *next=slow->next;
        while (next) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        while (pre) {
            if (head->val+pre->val > max) {
                max = head->val+pre->val;
            }
            head = head->next;
            pre = pre->next;
        }
        return max;
    }
};