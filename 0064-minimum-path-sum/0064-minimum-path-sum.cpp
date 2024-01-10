class Solution {
    int m, n;
    vector<vector<int>> rec;
    deque<pair<int, int>> q;
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        rec = vector<vector<int>>(m, vector<int>(n, 0));
        rec[0][0] = grid[0][0];
        q.push_back({0, 0});

        while (!q.empty()) {
            // cout << "x: " << q.front().first << ", y: " << q.front().second << endl;
            NextStep(grid);
            q.pop_front();
        }

        return rec[m-1][n-1];
    }

    void NextStep(const vector<vector<int>>& grid) {
        int x = q.front().first, y = q.front().second;

        // down
        if (y+1 < n && (rec[x][y+1] == 0 || rec[x][y]+grid[x][y+1]<rec[x][y+1])) {
            q.push_back({x, y+1});
            rec[x][y+1] = rec[x][y]+grid[x][y+1];
        }

        // right
        if (x+1 < m && (rec[x+1][y] == 0 || rec[x][y]+grid[x+1][y]<rec[x+1][y])) {
            q.push_back({x+1, y});
            rec[x+1][y] = rec[x][y]+grid[x+1][y];
        }
    }
};