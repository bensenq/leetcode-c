#define min(x, y) (x < y ? x : y)

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dp[len1+1][len2+1];
    int t;
    for (int i = 0; i <= len1; i++) dp[i][0] = i;
    for (int j = 0; j <= len2; j++) dp[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                t = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(t+1, dp[i-1][j-1]+2);
            }
        }
    }
    return dp[len1][len2];
}
