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
    int cnt, target;
    unordered_map<long, int> ps; // prefix_sum
public:
    void SearchPath(TreeNode* node, long sum) {
        if (node == nullptr)
            return;
        
        // update the prefix sum for descendant
        sum += node->val;

        if (sum == target)
            cnt++;
        
        if (ps[sum-target] > 0)
            cnt += ps[sum-target];

        // the hash table should be updated after checking the ancestor's 
        // prefix sum
        ps[sum]++;

        // search the descendant nodes
        SearchPath(node->left, sum);
        SearchPath(node->right, sum);

        // clear the information before turn back to the parent node
        ps[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        cnt = 0;
        target = targetSum;

        SearchPath(root, 0);

        return cnt;
    }
};