class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        // Target: return a matrix ans,
            // ans[i][j] = sum(matrix[r][c], i-k <= r <= i+k, j - k <= c <= j + k)
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> sum(row + 1, vector<int>(col + 1));

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                sum[r + 1][c + 1] = sum[r + 1][c] + sum[r][c + 1] -
                                    sum[r][c] + mat[r][c];
            }
        }

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                int r1, c1, r2, c2;

                r1 = max(0, r - k);
                c1 = max(0, c - k);
                r2 = min(row - 1, r + k) + 1;
                c2 = min(col - 1, c + k) + 1;

                mat[r][c] = sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
            }
        }

        return mat;
    }
};