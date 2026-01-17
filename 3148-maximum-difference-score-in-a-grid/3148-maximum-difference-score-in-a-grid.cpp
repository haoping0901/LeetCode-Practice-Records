class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        // Input: vec. grid of size m*n, grid[i][j] > 0
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> sum(row + 1, vector<int>(col + 1, INT_MAX));
        int ans = INT_MIN;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                sum[r + 1][c + 1] = min({sum[r + 1][c], sum[r][c + 1], grid[r][c]});
                ans = max(ans, grid[r][c] - min(sum[r + 1][c], sum[r][c + 1]));
            }
        }

        return ans;
    }
};