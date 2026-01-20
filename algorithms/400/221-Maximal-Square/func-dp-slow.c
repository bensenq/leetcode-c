#define min(a,b) (a)>(b)?(b):(a)
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int ans = 0;
    int m = matrixSize, n = matrixColSize[0];
    int possible = min(m, n);
    bool dp[possible+1][m][n];
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                dp[1][i][j] = true;
                count++;
            } else {
                dp[1][i][j] = false;
            }
        }
    }
    if (count == 0) return 0;
    ans++;
    int k;
    for (k = 2; k <= possible; k++) {
        count = 0;
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                if (dp[k-1][i][j] && dp[k-1][i+1][j] && dp[k-1][i][j+1] && dp[k-1][i+1][j+1]) {
                    dp[k][i][j] = true;
                    count++;
                } else {
                    dp[k][i][j] = false;
                }
            }
        }
        if(count == 0) break;
        ans++;
    }
    return ans*ans;
}