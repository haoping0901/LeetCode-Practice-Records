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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *del_node = root, *del_parent = nullptr, *update_node;

        while (del_node != nullptr) {
            if (key > del_node->val) {
                del_parent = del_node;
                del_node = del_node->right;
            } else if (key < del_node->val) {
                del_parent = del_node;
                del_node = del_node->left;
            } else {
                if (del_node->left == nullptr && del_node->right == nullptr) {
                    // no descendant
                    if (del_node == root)
                        root = nullptr;
                    else {
                        if (del_parent->val < key) {
                            del_parent->right = nullptr;
                        } else {
                            del_parent->left = nullptr;
                        }
                    }
                    delete del_node;
                    break;
                } else if (del_node->left == nullptr && del_node->right != nullptr) {
                    // only right sub-tree
                    if (del_node != root) {
                        if (del_parent->val < key) {
                            del_parent->right = del_node->right;
                        } else {
                            del_parent->left = del_node->right;
                        }
                    } else {
                        root = del_node->right;
                    }

                    delete del_node;
                    break;
                } else if (del_node->left != nullptr && del_node->right == nullptr) {
                    // only left sub-tree
                    if (del_node != root) {
                        if (del_parent->val < key) {
                            del_parent->right = del_node->left;
                        } else {
                            del_parent->left = del_node->left;
                        }
                    } else {
                        root = del_node->left;
                    }

                    delete del_node;
                    break;
                } else {
                    // both sides exist sub-tree
                    // select the largest value in left sub-tree
                    update_node = del_node->left;
                    TreeNode *update_node_parent = del_node;

                    // find the maximum in left sub-tree
                    while (update_node->right) {
                        update_node_parent = update_node;
                        update_node = update_node->right;
                    }

                    // update the deleted node with the found node
                    if (del_node != root) {
                        if (del_parent->val < key) {
                            del_parent->right = update_node;
                        } else {
                            del_parent->left = update_node;
                        }
                    } else {
                        root = update_node;
                    }

                    // update the found node 
                    if (del_node->left != update_node) {
                        update_node_parent->right = update_node->left;
                        update_node->left = del_node->left;
                    }
                    update_node->right = del_node->right;

                    delete del_node;
                    break;
                }
            }
        }

        return root;
    }
};