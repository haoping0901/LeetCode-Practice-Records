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
    int root_idx;
public:
    TreeNode* Build(const vector<int>& preorder, const vector<int>& inorder, const int& left, 
                    const int& right) {
        if (left > right) return nullptr;

        int pivot = left;
        while (preorder[root_idx] != inorder[pivot]) pivot++;

        TreeNode* new_node = new TreeNode(preorder[root_idx]);
        root_idx++;
        new_node->left = Build(preorder, inorder, left, pivot-1);
        new_node->right = Build(preorder, inorder, pivot+1, right);

        return new_node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        root_idx = 0;
        return Build(preorder, inorder, 0, preorder.size()-1);
    }
};