/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    void IsLeaf(Node* node) {
        if (node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf \
                && node->bottomRight->isLeaf && node->topLeft->val == node->topRight->val \
                && node->topLeft->val == node->bottomLeft->val \
                && node->topLeft->val == node->bottomRight->val) {
            node->val = node->topLeft->val;

            delete node->topLeft;
            node->topLeft = nullptr;
            delete node->topRight;
            node->topRight = nullptr;
            delete node->bottomLeft;
            node->bottomLeft = nullptr;
            delete node->bottomRight;
            node->bottomRight = nullptr;
        } else
            node->isLeaf = false;
    }

    Node* MakeQuadTree(const int& x0, const int& x1, const int& y0, const int& y1, \
                       const vector<vector<int>>& grid) {
        Node* ret = new Node(grid[x0][y0], true);
        if (x0 == x1) 
            return ret;

        int half_x = (x0+x1+1)>>1, half_y = (y0+y1+1)>>1;

        ret->topLeft = MakeQuadTree(x0, half_x-1, y0, half_y-1, grid);
        ret->topRight = MakeQuadTree(x0, half_x-1, half_y, y1, grid);
        ret->bottomLeft = MakeQuadTree(half_x, x1, y0, half_y-1, grid);
        ret->bottomRight = MakeQuadTree(half_x, x1, half_y, y1, grid);

        // check leaf node
        IsLeaf(ret);
        
        return ret;
    }

    Node* construct(vector<vector<int>>& grid) {
        int len = grid.size(), half_len = len>>1;
        if (len == 1) return new Node(grid[0][0], true);

        Node* ret = new Node(grid[0][0], true);

        ret->topLeft = MakeQuadTree(0, half_len-1, 0, half_len-1, grid);
        ret->topRight = MakeQuadTree(0, half_len-1, half_len, len-1, grid);
        ret->bottomLeft = MakeQuadTree(half_len, len-1, 0, half_len-1, grid);
        ret->bottomRight = MakeQuadTree(half_len, len-1, half_len, len-1, grid);
        
        IsLeaf(ret);

        return ret;
    }
};