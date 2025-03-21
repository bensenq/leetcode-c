/* dp: bottom-up construction */
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    int i;
    bool dp[n+1];
    dp[0] = true;
    for (i = 1; i <= n; i++) {
        dp[i] = false;
    }
    i = 0;
    while(i < n) {
        if (dp[i] == true) {
            for(int j = 0; j < wordDictSize; j++) {
                int len = strlen(wordDict[j]);
                if (strncmp(s+i, wordDict[j], len) == 0) {
                    dp[i+len] = true;
                }
            }
        }
        i++;
    }
    return dp[n];
}