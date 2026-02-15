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
    vector<int> nextLargerNodes(ListNode* head) {
        // Find the first value of the nearest node after each node_i
        // Iterate head, for each node ni
            // check if the stack st that staging the node that has not found 
            // the larger node is smaller than ni
            // If so, than record the ni to return vec ans and pop it from st
        // push ni into st
        vector<int> ans;
        stack<int> st;
        int idx = 0;

        while (head != nullptr) {
            while (!st.empty() && ans[st.top()] < head->val) {
                ans[st.top()] = head->val;
                st.pop();
            }

            ans.push_back(head->val);
            st.push(idx++);
            head = head->next;
        }

        while (!st.empty()) {
            ans[st.top()] = 0;
            st.pop();
        }

        return ans;
    }
};