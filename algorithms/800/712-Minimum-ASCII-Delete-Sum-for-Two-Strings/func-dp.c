#define min(x, y) (x < y ? x : y)

int minimumDeleteSum(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[len1+1][len2+1];
    int t;
    dp[0][0] = 0;
    for (int i = 1; i <= len1; i++)  {
        dp[i][0] = dp[i-1][0] + s1[i-1];
    }
    for (int j = 1; j <= len2; j++) {
        dp[0][j] = dp[0][j-1] + s2[j-1];
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                t = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                dp[i][j] = min(t, dp[i-1][j-1]+s1[i-1]+s2[j-1]);
            }
        }
    }
    return dp[len1][len2];
}
