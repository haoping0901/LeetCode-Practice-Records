class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        // prefix sum of row
        int row = grid.size(), col = grid[0].size();
        // {cnt_X, cnt_Y}
        vector<pair<int, int>> sum(col);
        int ans = 0;

        for (int r = 0; r < row; ++r) {
            pair<int, int> s;
            for (int c = 0; c < col; ++c) {
                if (grid[r][c] == 'X')
                    ++s.first;
                else if (grid[r][c] == 'Y')
                    ++s.second;
                
                sum[c].first += s.first;
                sum[c].second += s.second;

                if (sum[c].first == sum[c].second && sum[c].first > 0)
                    ++ans;
            }
        }

        return ans;
    }
};