#define MIN(x, y) (x < y ? x : y)
int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    int m = dungeonSize, n = dungeonColSize[0];
    int **dp = malloc(sizeof(int*) * m);
    for (int i = 0; i < dungeonSize; i++) {
        dp[i] = calloc(sizeof(int), n);
    }
    dp[m-1][n-1] = dungeon[m-1][n-1]>= 0 ? 1 : 1-dungeon[m-1][n-1];
    for (int i = n-2; i >=0; i--) {
        dp[m-1][i] = dp[m-1][i+1] - dungeon[m-1][i];
        if (dp[m-1][i] <= 0) dp[m-1][i]  = 1;
    }

    for (int i = m-2; i >= 0; i--) {
        dp[i][n-1] = dp[i+1][n-1] - dungeon[i][n-1];
        if (dp[i][n-1] <= 0) dp[i][n-1]  = 1;
    }

    for (int i = m-2; i >= 0; i--) {
        for (int j = n-2; j >= 0; j--) {
            int min = MIN(dp[i+1][j], dp[i][j+1]);
            dp[i][j] = min - dungeon[i][j];
            if (dp[i][j] <= 0) dp[i][j]  = 1;
        }
    }

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    int ans = dp[0][0];
    for (int i = 0; i < dungeonSize; i++) {
        free(dp[i]);
    }    
    free(dp);
    return ans;
}
