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
    priority_queue<int> pq;
public:
    void InitPQ(const TreeNode* const node) {
        pq.push(node->val);
        if (node->left) InitPQ(node->left);
        if (node->right) InitPQ(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        InitPQ(root);
        int val = pq.top(), ret = INT_MAX;
        pq.pop();

        while (!pq.empty()) {
            ret = min(ret, abs(val-pq.top()));
            val = pq.top();
            pq.pop();
        }

        return ret;
    }
};