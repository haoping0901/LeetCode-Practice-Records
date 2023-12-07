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
    void FindLeaf(TreeNode* node, vector<int>& rec) {
        if (node->left)
            FindLeaf(node->left, rec);
        if (node->right)
            FindLeaf(node->right, rec);
        
        // Store the value of leaf node 
        if (!node->left && !node->right) 
            rec.push_back(node->val);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> rec1, rec2;

        FindLeaf(root1, rec1);
        FindLeaf(root2, rec2);

        if (rec1.size() != rec2.size())
            return false;
        else {
            for (int i=0; i<rec1.size(); i++) {
                if (rec1[i] != rec2[i])
                    return false;
            }
        }
        
        return true;
    }
};