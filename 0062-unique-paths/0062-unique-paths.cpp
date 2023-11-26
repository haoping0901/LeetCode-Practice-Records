class Solution {
public:
    int uniquePaths(int m, int n) {
        int map[m][n];
        bool rec[m][n];
        queue<int> x, y;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                map[i][j] = 0;
                rec[i][j] = false;
            }
        }
        x.push(0);
        y.push(0);
        map[0][0] = 1;
        rec[0][0] = true;

        while (!x.empty()) {
            int pos_x=x.front(), pos_y=y.front();
            x.pop();
            y.pop();

            if (pos_x+1 < m) {
                map[pos_x+1][pos_y] += map[pos_x][pos_y];

                if (!rec[pos_x+1][pos_y]) {
                    x.push(pos_x+1);
                    y.push(pos_y);
                    rec[pos_x+1][pos_y] = true;
                }
            }
            if (pos_y+1 < n) {
                map[pos_x][pos_y+1] += map[pos_x][pos_y];
                
                if (!rec[pos_x][pos_y+1]) {
                    x.push(pos_x);
                    y.push(pos_y+1);
                    rec[pos_x][pos_y+1] = true;
                }
            }
        }

        return map[m-1][n-1];
    }
};