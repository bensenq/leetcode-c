//HOLD 0, UNHOLD 1
//dp[i][HOLD] = max(dp[i-1][HOLD], dp[i-1][UNHOLD]-prices[i])
//dp[i][UNHOLD] = max(dp[i-1][UNHOLD], dp[i-1][HOLD]+prices[i])
//result = dp[pricesSize-1][UNHOLD]

/*
 *              7   1   5   3   6   4
 * hold        -7  -1  -1   1   1   1  
 * unhold       0   0   4   4   4   5
*/

#define max(a,b) (a>b?a:b)

int maxProfit(int* prices, int pricesSize) {
    int dp[pricesSize][2];
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for(int i = 1; i < pricesSize; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
    }
    return dp[pricesSize-1][1];
}