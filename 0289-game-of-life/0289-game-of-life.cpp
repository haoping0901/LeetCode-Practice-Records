class Solution {
    ssize_t last_row_idx_, last_col_idx_;
public:
    void RuleCheck(vector<vector<int>>& board, const ssize_t& r, const ssize_t& c) {
        // 1 && neighbor(1) < 2 -> die
        // 1 && neighbor(1) == 2 || neighbor(1) == 3 -> live
        // 1 && neighbor(1) > 3 -> die
        // 0 && neighbor(1) == 3 -> live

        unsigned int cnt = 0;
        for (ssize_t x = max(r-1, static_cast<ssize_t> (0)); x <= min(r+1, last_row_idx_); ++x) 
            for (ssize_t y = max(static_cast<ssize_t> (0), c-1); y <= min(c+1, last_col_idx_); ++y) 
                cnt += board[x][y] & 0x1;

        if (cnt == 3 || cnt - board[r][c] == 3)
            board[r][c] |= 0x2;
    }

    void gameOfLife(vector<vector<int>>& board) {
        last_row_idx_ = board.size()-1, last_col_idx_ = board[0].size()-1;

        // iterate the matrix and check its neighbors
        for (ssize_t r=0; r<=last_row_idx_; ++r) 
            for (ssize_t c=0; c<=last_col_idx_; ++c) 
                RuleCheck(board, r, c);

        // update the matrix
        for (ssize_t r=0; r<=last_row_idx_; ++r) 
            for (ssize_t c=0; c<=last_col_idx_; ++c) 
                board[r][c] >>= 1;
    }
};