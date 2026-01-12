class NumMatrix {
    vector<vector<int>> sum_;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();

        sum_.resize(row + 1, vector<int>(col + 1));

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                sum_[r + 1][c + 1] = sum_[r + 1][c] + sum_[r][c + 1] -
                                     sum_[r][c] + matrix[r][c];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum_[row2 + 1][col2 + 1] - sum_[row1][col2 + 1] -
               sum_[row2 + 1][col1] + sum_[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */