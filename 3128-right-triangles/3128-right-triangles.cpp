class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        // Right triangle: grid[i][j] == grid[i +/- n][j] == grid[i][j +/- n] == 1
        // Target: amount of right triangle

        // {row / col, num of 1} => record number of 1 in each row / col by hash tab.
        // Sum the ri * cj, j >= i
        vector<int> row, col;
        long long ret = 0;
        int i, j, r = grid.size(), c = grid[0].size();

        row = vector<int>(r, -1);
        col = vector<int>(c, -1);

        for (int i = 0; i < r; ++i) {
            for (j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    ++row[i];
                    ++col[j];
                }
            }
        }

        for (i = 0; i < r; ++i) {
            for (j = 0; j < c; ++j) {
                if (grid[i][j] == 1)
                    ret += row[i] * col[j];
            }
        }

        return ret;
    }
};