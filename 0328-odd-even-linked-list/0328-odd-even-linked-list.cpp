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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        int cnt=0;
        ListNode *odd=nullptr, *even=nullptr, *odd_head, *even_head;

        while (head != nullptr) {
            if (cnt%2 == 0) {
                if (even == nullptr) {
                    even_head = head;
                    even = head;
                } else {
                    even->next = head;
                    even = head;
                }
            } else {
                if (odd == nullptr) {
                    odd_head = head;
                    odd = head;
                } else {
                    odd->next = head;
                    odd = head;
                }
            }

            head = head->next;
            cnt++;
        }

        
        even->next = odd_head;
        odd->next = nullptr;

        return even_head;
    }
};