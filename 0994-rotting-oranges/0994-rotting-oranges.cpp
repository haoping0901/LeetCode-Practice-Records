class Solution {
    int x_size, y_size, fresh, max_steps;
public:
    void CheckAdjacent(deque<vector<int>>& q, vector<vector<bool>>& visited, 
                       const vector<vector<int>>& grid) {
        // top
        if (q.front()[0]-1 >= 0 && !visited[q.front()[0]-1][q.front()[1]] 
                && grid[q.front()[0]-1][q.front()[1]] == 1) {
            visited[q.front()[0]-1][q.front()[1]] = true;
            fresh--;
            vector<int> tmp{q.front()[0]-1, q.front()[1], q.front()[2]+1};
            max_steps = max(max_steps, q.front()[2]+1);
            q.push_back(tmp);
        }
        
        // down
        if (q.front()[0]+1 < x_size  && !visited[q.front()[0]+1][q.front()[1]] 
                && grid[q.front()[0]+1][q.front()[1]] == 1) {
            visited[q.front()[0]+1][q.front()[1]] = true;
            fresh--;
            vector<int> tmp{q.front()[0]+1, q.front()[1], q.front()[2]+1};
            max_steps = max(max_steps, q.front()[2]+1);
            q.push_back(tmp);
        }
        
        // left
        if (q.front()[1]-1 >= 0 && !visited[q.front()[0]][q.front()[1]-1] 
                && grid[q.front()[0]][q.front()[1]-1] == 1) {
            visited[q.front()[0]][q.front()[1]-1] = true;
            fresh--;
            vector<int> tmp{q.front()[0], q.front()[1]-1, q.front()[2]+1};
            max_steps = max(max_steps, q.front()[2]+1);
            q.push_back(tmp);
        }

        // top
        if (q.front()[1]+1 < y_size && !visited[q.front()[0]][q.front()[1]+1] 
                && grid[q.front()[0]][q.front()[1]+1] == 1) {
            visited[q.front()[0]][q.front()[1]+1] = true;
            fresh--;
            vector<int> tmp{q.front()[0], q.front()[1]+1, q.front()[2]+1};
            max_steps = max(max_steps, q.front()[2]+1);
            q.push_back(tmp);
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        x_size = grid.size();
        y_size = grid[0].size();
        fresh = 0;
        max_steps = 0;

        deque<vector<int>> q;
        vector<vector<bool>> visited(x_size, vector<bool>(y_size, false));

        for (int i=0; i<x_size; i++) {
            for (int j=0; j<y_size; j++) {
                if (grid[i][j] == 2) {
                    vector<int> tmp{i, j, 0};
                    q.push_back(tmp);
                    visited[i][j] = true;
                } else if (grid[i][j] == 1) {
                    fresh++;
                } else {
                    visited[i][j] = true;
                }
            }
        }

        while (fresh > 0 && !q.empty()) {
            CheckAdjacent(q, visited, grid);
            q.pop_front();
        }

        if (fresh)
            return -1;
        return max_steps;
    }
};