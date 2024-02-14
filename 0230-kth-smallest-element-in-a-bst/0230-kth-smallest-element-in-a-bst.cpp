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
    bool find;
    int cnt, ret;
public:
    void Inorder(TreeNode* node, const int& k) {
        if (node->left) Inorder(node->left, k);

        if (find) return;
        cnt++;
        if (cnt == k) {
            find = true;
            ret = node->val;
            return;
        }

        if (node->right) Inorder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        find = false;
        cnt = 0;

        Inorder(root, k);

        return ret;
    }
};