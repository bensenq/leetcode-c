// 2D Dynamic Programming
//  if s[i] = s[j]：
//      dp[i][j] = d[i+1][j+1] + dp[i+1][j]
//  else：
//      dp[i][j] = dp[i+1][j]
/*              b   a   b   g   b   a   g
 *          b   5   2   2   1   1   0   0
 *          a   3   3   1   1   1   1   0
 *          g   2   2   2   2   1   1   1
 */
int numDistinct(char* s, char* t) {
    int sl = strlen(s);
    int tl = strlen(t);
    unsigned int dp[sl][tl], count = 0;
    for (int i = 1; i <= sl; i++) {
        if (s[sl-i] == t[tl-1]) {
            count++;
        }
        dp[sl-i][tl-1] = count;
    }
    for (int i = 2; i <= tl; i++) {
        dp[sl-i+1][tl-i] = 0;
        for (int j = i; j <= sl; j++) {
            if (s[sl-j] == t[tl-i]) {
                dp[sl-j][tl-i] = dp[sl-j+1][tl-i+1]+dp[sl-j+1][tl-i];
            } else {
                dp[sl-j][tl-i] = dp[sl-j+1][tl-i];
            }
        }
    }

    return dp[0][0];
}