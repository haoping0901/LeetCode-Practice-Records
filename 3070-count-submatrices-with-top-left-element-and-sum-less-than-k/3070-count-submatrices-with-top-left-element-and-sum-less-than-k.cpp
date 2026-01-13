class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        // prefix sum
        int ans = 0;
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> sum(row + 1, vector<int>(col + 1));

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                sum[r + 1][c + 1] = sum[r][c + 1] + sum[r + 1][c] -
                                    sum[r][c] + grid[r][c];
                ans += (sum[r + 1][c + 1] <= k);
            }
        }

        return ans;
    }
};