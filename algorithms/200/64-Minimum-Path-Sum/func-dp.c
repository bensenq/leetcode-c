// as 63-Unique-Paths

#define MIN(x, y) (x < y ? x : y)

int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    int flag;
    int dp[m*n];
    dp[m*n-1] = grid[m-1][n-1];
    for (int i = n - 2; i >= 0; i--) {
        // dp[m-1][i] = dp[m-1][i+1] + grid[m-1][i]
        dp[(m-1)*n + i] = dp[(m-1)*n + i + 1] + grid[m-1][i];
    }
    
    for (int i = m - 2; i >= 0; i--) {
        // dp[i][n-1] = dp[i+1][n-1] + grid[i][n-1]
        dp[i*n + n - 1] = dp[(i+1)*n + n - 1] + grid[i][n-1];
    }
    
    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            // dp[i][j] = MIN(dp[i+1][j], dp[i][j+1]) + grid[i][j]
            dp[i*n + j] = MIN(dp[(i+1)*n + j], dp[i*n + j + 1]) + grid[i][j];
        }
    }
    
    return dp[0];
}