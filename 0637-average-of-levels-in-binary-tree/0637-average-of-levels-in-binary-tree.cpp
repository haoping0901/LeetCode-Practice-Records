/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        int cnt = 1;
        deque<TreeNode*> q;
        vector<double> ret;

        q.push_back(root);
        while (!q.empty()) {
            int nxt_cnt = 0;
            double sum = 0;

            for (int i=0; i<cnt; i++) {
                TreeNode* node = q.front();
                q.pop_front();

                sum += node->val;
                if (node->left) {
                    nxt_cnt++;
                    q.push_back(node->left);
                }
                if (node->right) {
                    nxt_cnt++;
                    q.push_back(node->right);
                }
            }
            ret.push_back(sum/cnt);
            cnt = nxt_cnt;
        }

        return ret;
    }
};