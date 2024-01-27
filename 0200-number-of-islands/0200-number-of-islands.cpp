class Solution {
    int m, n;
    vector<vector<bool>> visited;
public:
    bool BFS(const vector<vector<char>>& grid, const int& i, const int&j) {
        if (grid[i][j] == '0') return false;

        // top
        if (i-1 >= 0 && !visited[i-1][j]) {
            visited[i-1][j] = true;
            BFS(grid, i-1, j);
        }

        // down
        if (i+1 < m && !visited[i+1][j]) {
            visited[i+1][j] = true;
            BFS(grid, i+1, j);
        }

        // left
        if (j-1 >= 0 && !visited[i][j-1]) {
            visited[i][j-1] = true;
            BFS(grid, i, j-1);
        }

        // right
        if (j+1 < n && !visited[i][j+1]) {
            visited[i][j+1] = true;
            BFS(grid, i, j+1);
        }

        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++) visited.push_back(vector(n, false));
        int cnt = 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (visited[i][j]) continue;

                if (BFS(grid, i, j)) cnt++;
            }
        }

        return cnt;
    }
};