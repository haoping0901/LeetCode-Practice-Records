class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0]) return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> rec(n, 0);
        if (!obstacleGrid[0][0]) rec[0] = 1;

        for (int i=0; i<m; i++) {
            if (obstacleGrid[i][0]) rec[0] = 0;

            for (int j=1; j<n; j++) {
                if (!obstacleGrid[i][j]) 
                    rec[j] += rec[j-1];
                else 
                    rec[j] = 0;
            }
        }

        return rec[n-1];
    }
};