/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool m_find_p, m_find_q;
    bool m_find;
    TreeNode *m_p, *m_q, *ret;
public:
    pair<bool, bool> FindNodes(TreeNode* node, bool find_p, bool find_q) {
        if (node == nullptr)
            return {find_p, find_q};
        
        bool ret_lp, ret_lq, ret_rp, ret_rq;

        if (m_find)
         return {find_p, find_q};
        else if (node == m_p) {
            m_find_p = true;
            if (m_find_q) {
                return {true, find_q};
            }

            tie(ret_lp, ret_lq) = FindNodes(node->left, find_p, find_q);
            tie(ret_rp, ret_rq) = FindNodes(node->right, find_p, find_q);

            find_p = true;
            find_q = (ret_lq || ret_rq);
        } else if (node == m_q) {
            m_find_q = true;
            if (m_find_p) {
                return {find_p, true};
            }

            tie(ret_lp, ret_lq) = FindNodes(node->left, find_p, find_q);
            tie(ret_rp, ret_rq) = FindNodes(node->right, find_p, find_q);

            find_p = (ret_lp || ret_rp);
            find_q = true;
        } else {
            tie(ret_lp, ret_lq) = FindNodes(node->left, find_p, find_q);
            tie(ret_rp, ret_rq) = FindNodes(node->right, find_p, find_q);

            find_p = (ret_lp || ret_rp);
            find_q = (ret_lq || ret_rq);
        }

        if (find_p && find_q && !m_find) {
            m_find = true;
            ret = node;
        }
        return {find_p, find_q};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        m_find_p = false;
        m_find_q = false;
        m_find = false;
        m_p = p;
        m_q = q;

        pair<bool, bool> _ = FindNodes(root, false, false);
        return ret;
    }
};