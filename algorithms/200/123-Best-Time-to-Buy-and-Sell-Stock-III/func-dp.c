//1st HOLD 0, 1st UNHOLD 1 2ed HOLD 2, 2ed UNHOLD
//dp[i][HOLD1] = max(dp[i-1][HOLD1], -prices[i])
//dp[i][UNHOLD1] = max(dp[i-1][UNHOLD1], dp[i][HOLD1]+prices[i])
//dp[i][HOLD2] = max(dp[i-1][HOLD2], dp[i][UNHOLD1]-prices[i])
//dp[i][UNHOLD2] = max(dp[i-1][UNHOLD2], dp[i][HOLD2]+prices[i])
//result = dp[pricesSize-1][UNHOLD2]

/*
 *              3   3   5   0   0   3   1   4
 * 1st hold    -3  -3  -3   0   0   0   0   0
 * 1st unhold   0   0   2   2   2   3   3   4
 * 2ed hold    -3  -3   0   0   0   0   2   2
 * 2ed unhold   0   0   2   2   2   3   3   6   
*/

#define max(a,b) (a>b?a:b)
#define HOLD1   0
#define UNHOLD1 1
#define HOLD2   2
#define UNHOLD2 3

int maxProfit(int* prices, int pricesSize) {
    int dp[pricesSize][4];
    dp[0][HOLD1] = -prices[0];
    dp[0][UNHOLD1] = 0;
    dp[0][HOLD2] = -prices[0];
    dp[0][UNHOLD2] = 0;
    for(int i = 1; i < pricesSize; i++) {
        dp[i][HOLD1] = max(dp[i-1][HOLD1], -prices[i]);
        dp[i][UNHOLD1] = max(dp[i-1][UNHOLD1], dp[i][HOLD1]+prices[i]);
        dp[i][HOLD2] = max(dp[i-1][HOLD2], dp[i][UNHOLD1]-prices[i]);
        dp[i][UNHOLD2] = max(dp[i-1][UNHOLD2], dp[i][HOLD2]+prices[i]);
    }
    return dp[pricesSize-1][UNHOLD2];
}
