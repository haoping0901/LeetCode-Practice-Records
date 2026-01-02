class Solution {
    void AddAnswer(vector<int>& ans, const int val) {
        if (val > ans[0]) {
            ans[2] = ans[1];
            ans[1] = ans[0];
            ans[0] = val;
        } else if (val != ans[0] && val > ans[1]) {
            ans[2] = ans[1];
            ans[1] = val;
        } else if (val != ans[0] && val != ans[1] && val > ans[2]) {
            ans[2] = val;
        }
    }
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        // Target: biggest three distinct rhombus sums in decreasing order
        // For each elements, only take the left-below direction as the starting direction
        // Brute force: min(m, n)^2 * mn
        // prefix sum: min(m, n) * mn
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> ps_diag(row + 1, vector<int>(col + 2));
        vector<vector<int>> ps_anti_diag(ps_diag);
        vector<int> ans;
        set<int> rec;

        for (int r = 1; r <= row; ++r) {
            for (int c = 1; c <= col; ++c) {
                ps_diag[r][c] = ps_diag[r - 1][c - 1] + grid[r - 1][c - 1];
                ps_anti_diag[r][c] = ps_anti_diag[r - 1][c + 1] + grid[r - 1][c - 1];
            }
        }

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                rec.insert(grid[r][c]);
                if (rec.size() > 3)
                    rec.erase(rec.begin());

                for (int dr = r + 2; dr < row; dr += 2) {
                    int sum = 0;
                    int dc = c;
                    int lr = (r + dr) >> 1, lc = c - ((dr - r) >> 1);
                    int rr = lr,  rc = c + ((dr - r) >> 1);
                    if (lc < 0 || rc >= col)
                        break;

                    // left-top
                    sum += ps_anti_diag[lr + 1][lc + 1] - ps_anti_diag[r][c + 2];

                    // left-bottom
                    sum += ps_diag[dr + 1][dc + 1] - ps_diag[lr][lc];

                    // right-bottom
                    sum += ps_anti_diag[dr + 1][dc + 1] - ps_anti_diag[rr][rc + 2];

                    // right-top
                    sum += ps_diag[rr + 1][rc + 1] - ps_diag[r][c];

                    // Remove overlapped end-points
                    sum -= grid[r][c] + grid[dr][dc] + grid[lr][lc] + grid[rr][rc];

                    rec.insert(sum);
                    if (rec.size() > 3)
                        rec.erase(rec.begin());
                }
            }
        }

        ans = vector<int>(rec.rbegin(), rec.rend());
        return ans;
    }
};