#define max(a, b) a > b ? a : b

int maxProfit(int* prices, int pricesSize, int fee) {
    int dp[2];  //0 HOLD; 1 UNHOLD
    dp[0] = -prices[0];
    dp[1] = 0;
    for (int i = 1; i < pricesSize; i++) {
        dp[0] = max(dp[0], dp[1]-prices[i]);
        dp[1] = max(dp[1], dp[0]+prices[i]-fee);
    }
    return dp[1];
}