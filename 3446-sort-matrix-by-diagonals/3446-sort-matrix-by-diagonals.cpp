class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        // Target: reorder all diagonals by following rules:
            // bottom-left triangle (including the middle diagonal): non-increasing
            // Others: non-decreasing order
        // Iterate all diagonals, (n)
            // for each diagonals, rec. all elements and sort it (n + nlogn)
            // then fill the result back to the diagonal dealing with now (n)
        int n = grid.size(), r, c, i;

        for (int d = 0; d < n; ++d) {
            vector<int> diag;
            for (r = d, c = 0; r < n; ++r, ++c)
                diag.push_back(grid[r][c]);
            
            sort(diag.begin(), diag.end(), greater<int>());

            for (r = d, c = 0, i = 0; r < n; ++r, ++c, ++i)
                grid[r][c] = diag[i];
        }

        // top-right
        for (int d = 1; d < n; ++d) {
            vector<int> diag;
            for (c = d, r = 0; c < n; ++r, ++c)
                diag.push_back(grid[r][c]);
            
            sort(diag.begin(), diag.end());

            for (c = d, r = 0, i = 0; c < n; ++r, ++c, ++i)
                grid[r][c] = diag[i];
        }

        return grid;
    }
};