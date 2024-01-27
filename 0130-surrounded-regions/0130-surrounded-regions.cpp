class Solution {
    int m, n;
    vector<vector<bool>> visited;
public:
    void Flip(vector<vector<char>>& board, const int& i, const int& j) {
        if (board[i][j] == 'X') return;

        // top
        if (i-1 >= 0 && !visited[i-1][j]) {
            visited[i-1][j] = true;

            if (board[i-1][j] == 'O') Flip(board, i-1, j);
        }

        // down
        if (i+1 < m && !visited[i+1][j]) {
            visited[i+1][j] = true;

            if (board[i+1][j] == 'O') Flip(board, i+1, j);
        }

        // left
        if (j-1 >= 0 && !visited[i][j-1]) {
            visited[i][j-1] = true;

            if (board[i][j-1] == 'O') Flip(board, i, j-1);
        }

        // right
        if (j+1 < n && !visited[i][j+1]) {
            visited[i][j+1] = true;

            if (board[i][j+1] == 'O') Flip(board, i, j+1);
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for (int i=0; i<m; i++) visited.push_back(vector(n, false));

        // top
        for (int i=0; i<n; i++) {
            if (visited[0][i]) 
                continue;

            visited[0][i] = true;
            if (board[0][i] == 'O') Flip(board, 0, i);
        }

        // down
        for (int i=0; i<n; i++) {
            if (visited[m-1][i]) 
                continue;

            visited[m-1][i] = true;
            if (board[m-1][i] == 'O') Flip(board, m-1, i);
        }

        // left
        for (int i=1; i<m-1; i++) {
            if (visited[i][0]) 
                continue;

            visited[i][0] = true;
            if (board[i][0] == 'O') Flip(board, i, 0);
        }

        // right
        for (int i=1; i<m-1; i++) {
            if (visited[i][n-1]) 
                continue;

            visited[i][n-1] = true;
            if (board[i][n-1] == 'O') Flip(board, i, n-1);
        }

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};