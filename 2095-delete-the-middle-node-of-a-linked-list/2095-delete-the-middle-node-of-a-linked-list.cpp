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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *cur=head, *cur2=head->next;

        if (cur2 == nullptr) {
            return nullptr;
        }

        // if (cur2 == nullptr) {
        //     head->next = nullptr;
        //     return head;
        // }

        while (cur != nullptr && cur2 != nullptr) {
            if (cur2->next != nullptr && cur2->next->next != nullptr) {
                cur = cur->next;
                cur2 = cur2->next->next;
            } else {
                cur->next = cur->next->next;
                return head;
            }
        }

        return head;
    }
};