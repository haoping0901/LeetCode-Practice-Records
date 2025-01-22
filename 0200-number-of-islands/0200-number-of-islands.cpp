class Solution {
    int m_, n_;

    bool IsValidCoordinate(const int& row, const int& col) const {
        return row >= 0 && row < m_ && col >= 0 && col < n_;
    }

    void DFS(const vector<vector<char>>& grid, 
             vector<vector<bool>>& visited, const int& row, 
             const int& col) const {
        visited[row][col] = true;
        // 判斷上下左右是否沒造訪過且為 1
            // 是的話就遞迴尋找
            // 是或不是都紀錄曾造訪過
        // top
        if (IsValidCoordinate(row-1, col) && !visited[row-1][col] && 
                grid[row-1][col] == '1') {
            DFS(grid, visited, row-1, col);
        }
        // down
        if (IsValidCoordinate(row+1, col) && !visited[row+1][col] && 
                grid[row+1][col] == '1') {
            DFS(grid, visited, row+1, col);
        }
        // left
        if (IsValidCoordinate(row, col-1) && !visited[row][col-1] && 
                grid[row][col-1] == '1') {
            DFS(grid, visited, row, col-1);
        }
        // right
        if (IsValidCoordinate(row, col+1) && !visited[row][col+1] && 
                grid[row][col+1] == '1') {
            DFS(grid, visited, row, col+1);
        }

        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // 遍歷所有點，對每個沒造訪過的路地用 DFS 走訪所有相連的陸地
        // 走訪過程會記錄曾經造訪過，結束後增加代表陸地數量的值的變數
        m_ = grid.size(), n_ = grid[0].size();
        vector<vector<bool>> visited(m_, vector<bool>(n_, false));

        int cnt = 0;
        for (int row=0; row<m_; ++row) {
            for (int col=0; col<n_; ++col) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    DFS(grid, visited, row, col);
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};