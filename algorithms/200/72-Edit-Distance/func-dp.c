// dynamic programming
#define min(x, y) (x < y ? x : y)

int minDistance(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int dp[len1+1][len2+1];
    int t;
    for (int i = 0; i <= len1; i++) dp[i][0] = i;
    for (int j = 0; j <= len2; j++) dp[0][j] = j;

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (word1[i] == word2[j]) {
                dp[i+1][j+1] = dp[i][j];
            } else {
                t = min(dp[i+1][j], dp[i][j+1]);
                dp[i+1][j+1] = min(t, dp[i][j]) + 1;
            }
        }
    }
    return dp[len1][len2];
}

int main() {
    char *w1 = strdup("intention");
    char *w2 = strdup("execution");
    return minDistance(w1, w2);
}