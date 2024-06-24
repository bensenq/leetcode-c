/* classic dp problem: LCS */
//ref:Introduction to Algorithms 3rd edtion
int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n = strlen(text2);
    short dp[m+1][n+1];
    for (int i = 0; i <= m; i++) dp[i][0] = 0;
    for (int j = 1; j <= n; j++) dp[0][j] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else {
                if (dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[m][n];
}