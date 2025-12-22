class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // Target: sort all diagonals of the given matrix
        int m = mat.size(), n = mat[0].size();
        int r, c;

        // [6, 5]
        // [4, 3]
        // [2, 1]
        // Output
        // [3, 5]
        // [1, 6]
        // [2, 4]
        
        // Iterate all diagonal
        for (int d = 1; d < m + n; ++d) {
            vector<int> diag;

            // rec. the val. to an arr.
            for (int r = max(m - d, 0), c = max(d - m, 0); r < m && c < n;
                 ++r, ++c)
                diag.push_back(mat[r][c]);
            
            // sort the arr. in ascending order
            sort(diag.begin(), diag.end());

            // fill back to the return mat.
            for (int r = max(m - d, 0), c = max(d - m, 0), i = 0;
                 r < m && c < n; ++r, ++c, ++i)
                mat[r][c] = diag[i];
        }

        return mat;
    }
};