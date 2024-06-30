int numSquares(int n) {
    int dp[n+1];
    int i = 1;
    while(i * i <= n) {
        dp[i*i] = 1; 
        int j = i * i + 1;
        i++;
        for (; j <= n && j < i*i; j++) {
            int min = j;            
            for (int k = 1; k*k <= j; k++) {
                if (dp[j-k*k] + 1 < min) min = dp[j-k*k] + 1;
            }
            dp[j] = min;
        }
        if (j > n) break;
    }
    return dp[n];
}