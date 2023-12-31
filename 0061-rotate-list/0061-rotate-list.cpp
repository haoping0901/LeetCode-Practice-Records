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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode *fast = head, *slow = head;

        // fast node
        for (int i=0; i<k; i++) {
            fast = fast->next;
            
            if (!fast) {
                fast = head;
                k %= i+1;
                i = -1;
            }
        }
        if (fast == slow) return head;

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        fast->next = head;
        if (slow->next != fast) fast = slow->next;
        slow->next = nullptr;
        
        return fast;
    }
};