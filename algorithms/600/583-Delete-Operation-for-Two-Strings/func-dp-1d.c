//DP: 1-Dimension Version
#define MIN(x, y) ((x) < (y) ? (x) : (y))

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int dp[len2 + 1];

    for (int j = 0; j <= len2; j++) {
        dp[j] = j;
    }

    for (int i = 1; i <= len1; i++) {
        // prev for up-left (dp[i-1][j-1])，init.  dp[i-1][0]
        int prev = dp[0];

        dp[0] = i;

        for (int j = 1; j <= len2; j++) {
            // temp for up(dp[i-1][j]) and it's also next up-left (dp[i-1][j+1-1])
            int temp = dp[j];

            if (word1[i-1] == word2[j-1]) {
                dp[j] = prev;
            } else {
                dp[j] = MIN(MIN(temp, dp[j-1])+1, prev+2);
            }

            // temp is also up-left for next round (dp[i-1][j+1-1])
            prev = temp;
        }
    }

    return dp[len2];
}
