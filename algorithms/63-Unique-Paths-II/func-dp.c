// as 62-Unique-Paths

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    int flag;
    int dp[m*n];
    flag = 0;
    for (int i = 0; i < n; i++) {
        if (flag == 0 && obstacleGrid[0][i] == 0) {
            dp[i] = 1;
        } else {
            dp[i] = 0;
            flag = 1;
        }
    }
    
    flag = 0;
    for (int i = 0; i < m; i++) {
        if (flag == 0 && obstacleGrid[i][0] == 0) {
            dp[i*n] = 1;
        } else {
            dp[i*n] = 0;
            flag = 1;
        }
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1)
                dp[i*n + j] = 0;
            else 
                dp[i*n + j] = dp[(i-1)*n + j] + dp[i*n + (j-1)];
        }
    }
    
    return dp[m*n-1];
}