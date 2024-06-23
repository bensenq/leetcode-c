int numTilings(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    long long dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    long long sum = 2;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] += sum * 2;
        dp[i] %= 1000000007;
        sum += dp[i-2];
    }
    return dp[n];
}