#define MIN(x, y) ((x) < (y) ? (x) : (y))

int minimumDeleteSum(char* s1, char* s2)  {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int dp[len2 + 1];

    dp[0] = 0;
    for (int j = 1; j <= len2; j++) {
        dp[j] = dp[j-1] + s2[j-1];
    }

    for (int i = 1; i <= len1; i++) {
        // prev for up-left (dp[i-1][j-1])，init.  dp[i-1][0]
        int prev = dp[0];

        dp[0] += s1[i-1];

        for (int j = 1; j <= len2; j++) {
            // temp for up(dp[i-1][j]) and it's also next up-left (dp[i-1][j+1-1])
            int temp = dp[j];

            if (s1[i-1] == s2[j-1]) {
                dp[j] = prev;
            } else {
                dp[j] = MIN(MIN(temp+s1[i-1], dp[j-1]+s2[j-1]), prev+s1[i-1]+s2[j-1]);
            }

            // temp is also up-left for next round (dp[i-1][j+1-1])
            prev = temp;
        }
    }

    return dp[len2];
}
