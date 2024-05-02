class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        unsigned int row_tail_idx = matrix[0].size()-1;
        unsigned int l = 0, r = matrix.size()-1, m = l + ((r-l) >> 1);

        // find the interval containing target from rows
        while (l < r) {
            if (matrix[m][row_tail_idx] >= target)
                r = m;
            else
                l = m+1;
            
            m = l + ((r-l) >> 1);
        }
        
        // find the interval containing target from columns
        unsigned int target_row = m;
        l = 0, r = row_tail_idx, m = l + ((r-l) >> 1);

        while (l < r) {
            if (matrix[target_row][m] >= target)
                r = m;
            else
                l = m+1;
            m = l + ((r-l) >> 1);
        }

        return matrix[target_row][m] == target;
    }
};