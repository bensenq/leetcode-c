int numDecodings(char * s){
    int result;
    int len = strlen(s);
    int *dp = malloc(sizeof(int) * len);
    if (s[len-1] == '0') dp[0] = 0;
    else dp[0] = 1;
    for (int i = 1; i < len; i++) {
        if (s[len-1-i] == '0') dp[i] = 0;
        else {
            dp[i] = dp[i-1];
            if ((s[len-i-1] == '1' && s[len-i] >= '0' && s[len-i] <= '9') ||
                (s[len-i-1] == '2' && s[len-i] >= '0' && s[len-i] <= '6')) {
                if (i > 1)
                    dp[i] += dp[i-2];
                else
                    dp[i] += 1;
            }
        }
    }
    result = dp[len-1];
    free(dp);
    return result;
}