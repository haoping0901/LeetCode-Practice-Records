class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Use the first row and column to indicate 
        // whether a particular column or row needs to be set to zero.
        bool col0_has0 = false;
        size_t last_row_idx = matrix.size()-1, last_col_idx = matrix[0].size()-1;

        
        for (size_t r=0; r<=last_row_idx; ++r) {
            if (matrix[r][0] == 0) col0_has0 = true;
            
            for (size_t c=1; c<=last_col_idx; ++c) 
                if (matrix[r][c] == 0)
                    matrix[r][0] = matrix[0][c] = 0;
        }
        
        // Set each element to zero based on the records 
        // in the first row or column.
        for (ssize_t r=last_row_idx; r>=0; --r) {
            for (size_t c=last_col_idx; c>0; --c) 
                if (matrix[r][0] == 0 || matrix[0][c] == 0)
                    matrix[r][c] = 0;
            
            if (col0_has0) matrix[r][0] = 0;
        }
    }
};