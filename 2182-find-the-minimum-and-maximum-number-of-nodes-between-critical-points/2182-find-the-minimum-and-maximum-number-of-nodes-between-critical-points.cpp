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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // critical point: local maxima/minima
        // find min/max distance between critical points
        // record leftmost/rightmost position of critical points
        // leftmost for finding max dist
        // rightmost for finding min dist
        int leftmost_idx = 1e5, rightmost_idx = 0, idx = 1;
        int max_dist = -1, min_dist = -1;
        vector<int> ret(2, -1);

        ListNode *l_node = head, *m_node = l_node->next, *r_node = m_node->next;
        if (!r_node) return ret;
        ret[0] = 1e5;    // min dist

        while (r_node) {
            // max/min critical point
            if (m_node->val > l_node->val && m_node->val > r_node->val
                || m_node->val < l_node->val && m_node->val < r_node->val) {
                leftmost_idx = min(leftmost_idx, idx);

                if (rightmost_idx) {
                    // cout << "idx: " << idx << ", ridx: " << rightmost_idx << endl;
                    ret[0] = min(ret[0], idx-rightmost_idx);
                }
                rightmost_idx = max(rightmost_idx, idx);
            }

            ++idx;
            l_node = l_node->next;
            m_node = m_node->next;
            r_node = r_node->next;
        }

        if (leftmost_idx == 1e5 || leftmost_idx == rightmost_idx) {
            ret[0] = ret[1] = -1;
            return ret;
        }
        ret[1] = rightmost_idx - leftmost_idx;

        return ret;
    }
};