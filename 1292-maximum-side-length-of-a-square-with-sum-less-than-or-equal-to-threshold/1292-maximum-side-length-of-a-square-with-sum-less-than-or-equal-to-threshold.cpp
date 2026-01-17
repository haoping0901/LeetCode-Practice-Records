class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        // Input:
            // mat: vec. of size m * n
            // threshold: a value which the sum of square sub-mat should <= than
        // prefix sum
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> sum(row + 1, vector<int>(col + 1));
        int ans = 0;

        auto check_sum = [&](int r1, int c1, int r2, int c2) -> int {
            return sum[r2 + 1][c2 + 1] - sum[r1][c2 + 1] - sum[r2 + 1][c1] +
                   sum[r1][c1];
        };

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                sum[r + 1][c + 1] = sum[r + 1][c] + sum[r][c + 1] - sum[r][c] +
                                    mat[r][c];
                if (r - ans >= 0 && c - ans >= 0 &&
                        check_sum(r - ans, c - ans, r, c) <= threshold)
                    ++ans;
            }
        }

        return ans;
    }
};