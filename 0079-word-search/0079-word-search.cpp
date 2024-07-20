class Solution {
    int rows_, cols_, str_len_;
    string word_;

    bool IsBorder(const int& r, const int& c) {
        if (r >= 0 && r < rows_ && c >= 0 && c < cols_)
            return false;
        
        return true;
    }

    bool NextStep(vector<vector<char>>& board, const int& r, const int& c, 
                  int word_idx, vector<vector<bool>>& visited) {
        if (board[r][c] == word_[word_idx]) {
            ++word_idx;

            if (word_idx == str_len_) return true;

            if (!IsBorder(r+1, c) && !visited[r+1][c]) {
                visited[r+1][c] = true;
                if (NextStep(board, r+1, c, word_idx, visited))
                    return true;
                visited[r+1][c] = false;
            }
            if (!IsBorder(r-1, c) && !visited[r-1][c]) {
                visited[r-1][c] = true;
                if (NextStep(board, r-1, c, word_idx, visited))
                    return true;
                visited[r-1][c] = false;
            }
            if (!IsBorder(r, c-1) && !visited[r][c-1]) {
                visited[r][c-1] = true;
                if (NextStep(board, r, c-1, word_idx, visited))
                    return true;
                visited[r][c-1] = false;
            }
            if (!IsBorder(r, c+1) && !visited[r][c+1]) {
                visited[r][c+1] = true;
                if (NextStep(board, r, c+1, word_idx, visited))
                    return true;
                visited[r][c+1] = false;
            }
        } 

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows_ = board.size();
        cols_ = board[0].size();
        str_len_ = word.length();
        word_ = word;
        vector<vector<bool>> visited(rows_, vector<bool>(cols_, false));

        // DFS each elements
        for (int c=0; c<cols_; ++c) {
            for (int r=0; r<rows_; ++r) {
                visited[r][c] = true;
                if (NextStep(board, r, c, 0, visited))
                    return true;

                // reset the matrix recording visit info.
                for (int v_r=0; v_r<rows_; ++v_r)
                    for (int v_c=0; v_c<cols_; ++v_c)
                        visited[v_r][v_c] = false;
            }
        }

        return false;
    }
};