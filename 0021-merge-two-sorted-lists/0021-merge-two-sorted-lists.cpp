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
        ListNode *ret, **concat_ptr = &ret;

        for (ListNode **select_ptr; list1 && list2; 
                *select_ptr=(*select_ptr)->next, 
                concat_ptr = &(*concat_ptr)->next) {
            select_ptr = (list1->val < list2->val) ? &list1 : &list2;
            *concat_ptr = *select_ptr;
        }
        if (list1) *concat_ptr = list1;
        if (list2) *concat_ptr = list2;

        return ret;
    }
};