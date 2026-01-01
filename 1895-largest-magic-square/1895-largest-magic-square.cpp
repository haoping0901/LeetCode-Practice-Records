class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        // Target: find the largest magic square
        // Brute force: m*n * m*n
        // prefix sum for each diagonal / row / column: O(m * n + min(m, n) * m * n * min(m, n))
        // Check if magic square exists from the size of min(m, n)
        vector<vector<int>> prefix_row(grid);
        vector<vector<int>> prefix_col(grid);
        vector<vector<int>> prefix_diag(grid);
        vector<vector<int>> prefix_anti_diag(grid);
        int row = grid.size(), col = grid[0].size();

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (c > 0)  // row
                    prefix_row[r][c] += prefix_row[r][c - 1];
                if (r > 0)  // col
                    prefix_col[r][c] += prefix_col[r - 1][c];
                if (c > 0 && r > 0) // diag
                    prefix_diag[r][c] += prefix_diag[r - 1][c - 1];
                if (r > 0 && c < col - 1)   // anit diag
                    prefix_anti_diag[r][c] += prefix_anti_diag[r - 1][c + 1];
            }
        }

        for (int check_size = min(row, col); check_size > 1; --check_size) {
            for (int r = 0; r + check_size - 1 < row; ++r) {
                for (int c = 0; c + check_size - 1 < col; ++c) {
                    bool not_meet = false;
                    // row
                    int target = prefix_row[r][c + check_size - 1];
                    if (c > 0)
                        target -= prefix_row[r][c - 1];
                    
                    for (int check_r = r + 1; check_r < r + check_size; ++check_r) {
                        int row_val = prefix_row[check_r][c + check_size - 1];
                        if (c > 0)
                            row_val -= prefix_row[check_r][c - 1];
                        
                        if (row_val != target) {
                            not_meet = true;
                            break;
                        }
                    }

                    if (not_meet)
                        continue;
                    
                    // col
                    for (int check_c = c; check_c < c + check_size; ++check_c) {
                        int col_val = prefix_col[r + check_size - 1][check_c];
                        if (r > 0)
                            col_val -= prefix_col[r - 1][check_c];
                        
                        if (col_val != target) {
                            not_meet = true;
                            break;
                        }
                    }

                    if (not_meet)
                        continue;
                    
                    // diag
                    int diag_val = prefix_diag[r + check_size - 1][c + check_size - 1];
                    if (r > 0 && c > 0)
                        diag_val -= prefix_diag[r - 1][c - 1];
                    
                    if (diag_val != target)
                        continue;
                    
                    // anti diag
                    int anti_diag_val = prefix_anti_diag[r + check_size - 1][c];
                    if (r > 0 && c + check_size < col)
                        anti_diag_val -= prefix_anti_diag[r - 1][c + check_size];
                    
                    if (anti_diag_val != target)
                        continue;
                    
                    return check_size;
                }
            }
        }

        return 1;
    }
};