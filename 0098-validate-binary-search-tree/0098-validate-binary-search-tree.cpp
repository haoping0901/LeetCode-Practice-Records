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
    bool isValidBST(TreeNode* root) {
        const TreeNode *pre = nullptr, *cur = root->left;
        deque<const TreeNode*> s;
        s.push_back(root);

        while (cur || !s.empty()) {
            while (cur) {
                s.push_back(cur);
                cur = cur->left;
            }
            cur = s.back();
            s.pop_back();

            if (pre && pre->val >= cur->val) return false;
            pre = cur;
            cur = cur->right;
        }

        return true;
    }
};