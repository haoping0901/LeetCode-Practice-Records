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
    int dfs(const TreeNode* const ptr) {
        int left_depth=0, right_depth=0;

        if (ptr->left != nullptr) 
            left_depth = dfs(ptr->left);
        if (ptr->right != nullptr)
            right_depth = dfs(ptr->right);
        
        if (left_depth > right_depth) {
            return 1+left_depth;
        } else {
            return 1+right_depth;
        }
    }
    
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        else 
            return dfs(root);
    }
};