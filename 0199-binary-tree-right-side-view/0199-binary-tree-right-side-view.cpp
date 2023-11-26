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
    // int cnt=1;
    vector<int> ret;
public:
    void bfs(TreeNode* node, int height) {
        if (height > ret.size()) {
            ret.push_back(node->val);
        }
        if (node->right != nullptr)
            bfs(node->right, height+1);
        if (node->left != nullptr)
            bfs(node->left, height+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return ret;
        else {
            bfs(root, 1);
        }

        return ret;
    }
};