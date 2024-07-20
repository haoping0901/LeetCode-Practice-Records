class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        // look at the row and then check the column
        // ex1
        // [3, 0]
        // [3, 0] [1, 7]
        // ex2
        // [5, 0, 0]
        // [5, 0, 0], [2, 5, 0]
        // [5, 0, 0], [2, 5, 0], [1, 1, 8]

        int row_size = rowSum.size(), col_size = colSum.size();
        vector<vector<int>> ret(row_size, vector<int>(col_size, 0));

        // Start checking from the first column of the first row.
        for (int r=0; r<row_size; ++r) {
            // Each time, assign the maximum acceptable value to this element.
            for (int c=0; c<col_size; ++c) {
                ret[r][c] = min(rowSum[r], colSum[c]);
                rowSum[r] -= ret[r][c], colSum[c] -= ret[r][c];
            }
        }

        return ret;
    }
};