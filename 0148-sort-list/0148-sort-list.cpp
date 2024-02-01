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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* pre;
        deque<ListNode*> q;

        // initialize the queue for merge sort
        while (head) {
            pre = head;
            q.push_back(head);

            head = head->next;
            pre->next = nullptr;
        }

        // merge sort
        while (q.size() > 1) {
            ListNode *l = q.front();
            q.pop_front();
            ListNode *r = q.front();
            q.pop_front();

            if (l->val <= r->val) {
                head = l;
                l = l->next;
            } else {
                head = r;
                r = r->next;
            }
            pre = head;

            while (l && r) {
                if (l->val <= r->val) {
                    pre->next = l;
                    l = l->next;
                } else {
                    pre->next = r;
                    r = r->next;
                }
                pre = pre->next;
            }

            if (l) pre->next = l;
            if (r) pre->next = r;


            q.push_back(head);
        }

        return q.front();
    }
};