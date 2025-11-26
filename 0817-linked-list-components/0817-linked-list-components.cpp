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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> rec;
        int ret = 0;
        bool in_n = false;

        for (const auto& n: nums)
            rec.insert(n);
        
        while (head) {
            if (rec.find(head->val) != rec.end()) {
                in_n = true;
            } else {
                if (in_n == true) {
                    ++ret;
                    in_n = false;
                }
            }

            head = head->next;
        }

        if (in_n == true)
            ++ret;
        return ret;
    }
};