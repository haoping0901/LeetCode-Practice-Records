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
    void mergeTwoLists(ListNode **list1, ListNode **list2) {
        ListNode **selected_node, *l1 = *list1, *l2 = *list2;

        for (; l1 && l2;) {
            selected_node = (l1->val < l2->val) ? &l1 : &l2;
            *list1 = *selected_node;
            list1 = &(*list1)->next;
            *selected_node = (*selected_node)->next;
        }

        if (l1) *list1 = l1;
        if (l2) *list1 = l2;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n_lists = lists.size();
        if (!n_lists) return nullptr;

        for (int interval=1; interval<n_lists; interval*=2) {
            for (int i=0; i+interval<n_lists; i+=interval<<1) 
                mergeTwoLists(&lists[i], &lists[i+interval]);
        }
        return lists[0];
    }
};