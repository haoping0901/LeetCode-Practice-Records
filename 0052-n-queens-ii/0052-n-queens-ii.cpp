class Solution {
    int board_size_;
    int cnt_ = 0;

    // true indicates the position can be placed; false indicates otherwise.
    vector<bool> col_status_, l2r_diag_status_, r2l_diag_status_;

    void SetStatus(const int& row, const int& col, const bool& status) {
        col_status_[col] = status;
        l2r_diag_status_[row-col+(board_size_-1)] = status;
        r2l_diag_status_[row+col] = status;
    }

    bool CheckStatus(const int& row, const int& col) const {
        return (col_status_[col] && l2r_diag_status_[row-col+(board_size_-1)] 
                && r2l_diag_status_[row+col]);
    }
    
    void FindPosition(const int& row) {
        // parameters list: the coordinates we placed
        if (row == board_size_) {
            ++cnt_;
            return;
        }

        for (int c=0; c<board_size_; ++c) {
            if (CheckStatus(row, c)) {
                // Upon finding a valid position, update the current record of 
                // valid placements.
                SetStatus(row, c, false);

                // Recursively search for valid positions in the subsequent 
                // row.
                FindPosition(row+1);

                // Restore the valid placement information to backtrack.
                SetStatus(row, c, true);
            }
        }
    }
public:
    int totalNQueens(int n) {
        // Recursive approach:
            // Each step modifies the board, making the unavailable positions 
            // unique to that step.
            // Therefore, we use recursion to explore potential placements for 
            // other pieces.
        board_size_ = n;
        col_status_ = vector<bool>(n, true);
        l2r_diag_status_ = vector<bool>((n<<1) - 1, true);
        r2l_diag_status_ = vector<bool>((n<<1) - 1, true);
        
        FindPosition(0);

        return cnt_;
    }
};