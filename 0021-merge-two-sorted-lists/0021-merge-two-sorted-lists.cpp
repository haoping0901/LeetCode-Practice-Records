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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return list1;
        else if (!list1 && list2) return list2;
        else if (list1 && !list2) return list1;

        // Select the linked list with smaller value in the first node as the head
        ListNode *head, *cur;
        if (list1->val > list2->val) {
            head = list2;
            list2 = list2->next;
        } else {
            head = list1;
            list1 = list1->next;
        }

        // link the node with smaller value to current node, and update the address
        cur = head;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                cur->next = list2;
                list2 = list2->next;
            } else {
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }

        // append the spare list to the end
        if (list1) {
            cur->next = list1;
        } else {
            cur->next = list2;
        }

        return head;
    }
};