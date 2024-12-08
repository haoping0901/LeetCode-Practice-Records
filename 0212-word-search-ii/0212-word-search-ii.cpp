class WordNode {
    bool is_word_ = false;
    vector<WordNode *> alphabets_rec_ = vector<WordNode *>(26, nullptr);
public:
    void SetWordEnd(const bool& status) {
        is_word_ = status;
    }
    bool IsWord() const {
        return is_word_;
    }
    WordNode **GetNode(const char& ch) {
        return &alphabets_rec_[ch - 'a'];
    }

    ~WordNode() {
        for (auto& node: alphabets_rec_) {
            if (node) {
                delete node;
                node = nullptr;
            }
        }
    }
};

class Solution {
    int board_row_size_, board_col_size_;
    WordNode *words_list_ = nullptr;
    vector<vector<bool>> visited_;
    vector<string> ans_;

    void CheckWordsList(const vector<vector<char>>& board, const int& row, 
                       const int& col, string& cur_str, WordNode *list) {
        visited_[row][col] = true;
        if (!list)
            return;
        
        if (list->IsWord()) {
            ans_.push_back(cur_str);
            list->SetWordEnd(false);
        }

        // top
        char next_ch;
        if (row > 0 && !visited_[row-1][col] 
                && *list->GetNode(board[row-1][col])) {
            next_ch = board[row-1][col];
            cur_str.push_back(next_ch);
            CheckWordsList(board, row-1, col, cur_str, 
                           *list->GetNode(next_ch));
            cur_str.pop_back();
        }
        // down
        if (row < board_row_size_-1 && !visited_[row+1][col] 
                && *list->GetNode(board[row+1][col])) {
            next_ch = board[row+1][col];
            cur_str.push_back(next_ch);
            CheckWordsList(board, row+1, col, cur_str, 
                           *list->GetNode(next_ch));
            cur_str.pop_back();
        }
        // left
        if (col > 0 && !visited_[row][col-1] 
                && *list->GetNode(board[row][col-1])) {
            next_ch = board[row][col-1];
            cur_str.push_back(next_ch);
            CheckWordsList(board, row, col-1, cur_str, 
                           *list->GetNode(next_ch));
            cur_str.pop_back();
        }
        // right
        if (col < board_col_size_-1 && !visited_[row][col+1]
                && *list->GetNode(board[row][col+1])) {
            next_ch = board[row][col+1];
            cur_str.push_back(next_ch);
            CheckWordsList(board, row, col+1, cur_str, 
                           *list->GetNode(next_ch));
            cur_str.pop_back();
        }

        visited_[row][col] = false;
    }

    void BuildWordList(const string& s) {
        WordNode *words_list = words_list_;
        for (const char& ch: s) {
            if (!*words_list->GetNode(ch))
                *words_list->GetNode(ch) = new WordNode;
            words_list = *words_list->GetNode(ch);
        }
        words_list->SetWordEnd(true);
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        board_row_size_ = board.size();
        board_col_size_ = board[0].size();
        words_list_ = new WordNode;
        visited_ = vector<vector<bool>>(board_row_size_, 
                                        vector<bool>(board_col_size_, false));

        // Construct a trie for all words
        // Complexity: num_words * max_word_len.
        for (const string& word: words)
            BuildWordList(word);

        // For each character on the board, invoke the DFS search function if 
        // a corresponding entry exists from the root of the trie.
        // Complexity: m * n * max_word_len.
        for (unsigned r=0; r<board_row_size_; ++r) {
            for (unsigned c=0; c<board_col_size_; ++c) {
                if (*words_list_->GetNode(board[r][c])) {
                    string tmp(1, board[r][c]);
                    CheckWordsList(board, r, c, tmp, 
                                   *words_list_->GetNode(board[r][c]));
                }
            }
        }

        return ans_;
    }
};