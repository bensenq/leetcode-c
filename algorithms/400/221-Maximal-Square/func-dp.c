//ref: https://leetcode.com/problems/maximal-square/?envType=problem-list-v2&envId=dynamic-programming
#define min3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))
#define max(a, b) ((a) > (b) ? (a) : (b))
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {
    int ans = 0;
    int m = matrixSize, n = matrixColSize[0];
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = 0;

    int max_side = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                dp[i+1][j+1] = min3(dp[i][j], dp[i+1][j], dp[i][j+1]) + 1;
                max_side = max(max_side, dp[i+1][j+1]);
            }
        }
    }
    return max_side*max_side;
}