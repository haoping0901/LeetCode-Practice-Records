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
    int maxLevelSum(TreeNode* root) {
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        int max=-numeric_limits<int>::max(), level=1, max_level, sum;

        while (!nodes.empty()) {
            sum = 0;
            for (int i=nodes.size(); i>0; i--) {
                sum += nodes.front()->val;

                if (nodes.front()->right)
                    nodes.push_back(nodes.front()->right);
                if (nodes.front()->left)
                    nodes.push_back(nodes.front()->left);
                
                nodes.pop_front();
            }

            // record the maximum
            if (sum > max) {
                max = sum;
                max_level = level;
            }
            level++;
        }

        return max_level;
    }
};