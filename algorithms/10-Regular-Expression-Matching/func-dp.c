//ref: https://leetcode.com/problems/regular-expression-matching/solutions/191830/java-dp-solution-beats-100-with-explanation/
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char * s, char * p){
    bool result;
    int sl = strlen(s) + 1;
    int pl = strlen(p) + 1;
    char **dp = malloc(sizeof(char *) * sl);
    for (int i = 0; i < sl; i++) {
        dp[i] = calloc(sizeof(char), pl);   //init to false
    }
    dp[0][0] = true;
    for (int j = 2; j < pl; j++) {
        dp[0][j] = p[j-1] == '*' && dp[0][j-2]; 
    }

    for (int j=1; j < pl; j++) {
        for (int i=1; i < sl; i++) {
            if (p[j-1] == s[i-1] || p[j-1] == '.') 
                dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*')
                dp[i][j] = dp[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]); 
        }
    }
    result = dp[sl-1][pl-1];
    for (int i = 0; i < sl; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;

}