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
    TreeNode* Subtree(const int& left, const int& right, const vector<int>& nums) {
        if (left > right) return nullptr;

        int insert_idx = (left+right) >> 1;
        TreeNode* new_node = new TreeNode(nums[insert_idx]);

        new_node->left = Subtree(left, insert_idx-1, nums);
        new_node->right = Subtree(insert_idx+1, right, nums);

        return new_node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Construct the TreeNode with the value in the middle of the range
        int nodes_num = nums.size(), root_idx = nodes_num >> 1;
        TreeNode* root = new TreeNode(nums[root_idx]);

        // DFS
        root->left = Subtree(0, root_idx-1, nums);
        root->right = Subtree(root_idx+1, nodes_num-1, nums);

        return root;
    }
};