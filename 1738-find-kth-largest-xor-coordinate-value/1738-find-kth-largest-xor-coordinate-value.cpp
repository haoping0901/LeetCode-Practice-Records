class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        // Input:
            // vec. mat w. size m * n, mat[i][j] >= 0
            // int k
            // val[a][b] == xor(mat[i][j]), 0 <= i <= a < m, 0 <= j <= b < n
        // Target: kth largest of val
        // prefix sum
        // rec. the result to an array rec
        // sort and return rec[m*n - k]
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> sum(row + 1, vector<int>(col + 1));
        vector<int> rec(row * col);
        int idx = 0;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                sum[r + 1][c + 1] = sum[r + 1][c] ^ sum[r][c + 1] ^
                                    sum[r][c] ^ matrix[r][c];
                rec[idx++] = sum[r + 1][c + 1];
            }
        }

        ranges::sort(rec.begin(), rec.end());

        return rec[row * col - k];
    }
};