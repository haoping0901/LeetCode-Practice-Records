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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *lt = nullptr, *geq = nullptr, *cur_lt = nullptr, *cur_geq = nullptr;

        while (head) {
            if (head->val < x) {
                if (!lt) {
                    lt = head;
                    cur_lt = head;
                } else {
                    cur_lt->next = head;
                    cur_lt = head;
                }
            } else {
                if (!geq) {
                    geq = head;
                    cur_geq = head;
                } else {
                    cur_geq->next = head;
                    cur_geq = head;
                }
            }
            head = head->next;
        }

        if (cur_lt)
            cur_lt->next = geq;
        else 
            lt = geq;
        if (cur_geq)
            cur_geq->next = nullptr;

        return lt;
    }
};