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
typedef struct Rec {
    TreeNode* node;
    int len;
    bool left;
} Rec;

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
            return 0;

        int max = 0;
        deque<Rec> track;

        track.push_back((Rec) {root->left, 1, true});
        track.push_back((Rec) {root->right, 1, false});

        while (!track.empty()) {
            if (track.front().node == nullptr) {
                max = (track.front().len-1 > max) ? track.front().len-1 : max;
                track.pop_front();
                continue;
            }

            // check the last direction, and push all child with the updated information
            if (track.front().left) {
                track.push_back((Rec) {track.front().node->left, 1, true});
                track.push_back((Rec) {track.front().node->right, track.front().len+1, false});
            } else {
                track.push_back((Rec) {track.front().node->left, track.front().len+1, true});
                track.push_back((Rec) {track.front().node->right, 1, false});
            }
            track.pop_front();
        }

        return max;
    }
};