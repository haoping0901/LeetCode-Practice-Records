class Solution {
    bool find_flg;
    int x_border, y_border;
    pair<int, int> dest;
    deque<pair<int, int>> path;
public:
    bool is_border(const pair<int, int>& pos) {
        if (pos.first == 0 || pos.second == 0 || pos.first == x_border || pos.second == y_border) {
            return true;
        }

        return false;
    }

    int find_path(const vector<vector<char>>& maze, vector<vector<bool>>& visited, const pair<int, int>& pos) {
        int path_cnt = 0;
        pair<int, int> tmp;
        
        // top
        tmp = make_pair(pos.first-1, pos.second);
        if (tmp.first >= 0 && visited[tmp.first][tmp.second] == false \
                && maze[tmp.first][tmp.second] == '.') {
            if (is_border(tmp)) {
                dest = tmp;
                find_flg = true;
                return 0;
            }

            visited[tmp.first][tmp.second] = true;
            path.push_back(tmp);
            path_cnt++;
        }

        // left
        tmp = make_pair(pos.first, pos.second-1);
        if (tmp.second >= 0 && visited[tmp.first][tmp.second] == false \
                && maze[tmp.first][tmp.second] == '.') {
            if (is_border(tmp)) {
                dest = tmp;
                find_flg = true;
                return 0;
            }

            visited[tmp.first][tmp.second] = true;
            path.push_back(tmp);
            path_cnt++;
        }

        // right
        tmp = make_pair(pos.first+1, pos.second);
        if (tmp.first <= x_border && visited[tmp.first][tmp.second] == false \
                && maze[tmp.first][tmp.second] == '.') {
            if (is_border(tmp)) {
                dest = tmp;
                find_flg = true;
                return 0;
            }

            visited[tmp.first][tmp.second] = true;
            path.push_back(tmp);
            path_cnt++;
        }

        // down
        tmp = make_pair(pos.first, pos.second+1);
        if (tmp.second <= y_border && visited[tmp.first][tmp.second] == false \
                && maze[tmp.first][tmp.second] == '.') {
            if (is_border(tmp)) {
                dest = tmp;
                find_flg = true;
                return 0;
            }

            visited[tmp.first][tmp.second] = true;
            path.push_back(tmp);
            path_cnt++;
        }

        return path_cnt;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) { 
        find_flg = false;
        x_border = maze.size()-1;
        y_border = maze[0].size()-1;
        
        int steps = 1, cnt = 0;
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
        pair<int, int> start_pos{entrance[0], entrance[1]};

        visited[start_pos.first][start_pos.second] = true;
        cnt += find_path(maze, visited, start_pos);

        // BFS
        while (!path.empty() && !find_flg) {
            int tmp = 0;
            for (int i=0; i<cnt; i++) {
                tmp += find_path(maze, visited, path.front());
                path.pop_front();
            }

            cnt = tmp;
            steps++;
        }

        // cout << dest.first << ' ' << dest.second << endl;

        if (find_flg)
            return steps;
        else
            return -1;
    }
};