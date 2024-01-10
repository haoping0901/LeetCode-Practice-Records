class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> rec(m, vector<int>(n, 0));

        for (int i=0; i<m; i++) {
            if (obstacleGrid[i][0])
                break;
            rec[i][0] = 1;
        }
        for (int j=0; j<n; j++) {
            if (obstacleGrid[0][j])
                break;
            rec[0][j] = 1;
        }

        for (int i=1; i<m; i++)
            for (int j=1; j<n; j++)
                if (!obstacleGrid[i][j]) 
                    rec[i][j] = rec[i-1][j] + rec[i][j-1];

        return rec[m-1][n-1];
    }
};