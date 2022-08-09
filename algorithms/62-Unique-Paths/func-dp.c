//DP Solution
//DP[i][j] = DP[i-1][j] + DP[i][j-1]
//DP[0][j] = DP[i][0] = 1

int uniquePaths(int m, int n) {
    int dp[m*n];
    dpp[0] = 1;
    for (int i = 1; i < n; i++) dp[i] = 1;
    for (int i = 1; i < m; i++) dp[i*n] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i*n + j] = dp[(i-1)*n + j] + dp[i*n + (j-1)];
        }
    }
    return dp[m*n-1];
}

int main() {
    return uniquePaths(3,7);
}