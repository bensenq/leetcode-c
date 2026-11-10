int climbStairs(int n, int* costs, int costsSize) {
    int *dp = malloc(sizeof(int) * (n+1));
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for(int j = 1; j <= 3 && i - j >= 0; j++) {
            int cost = dp[i-j] + costs[i-1] + j*j;
            if(cost < dp[i]) dp[i] = cost;
        }
    }
    int ans = dp[n];
    free(dp);
    return ans;
}
