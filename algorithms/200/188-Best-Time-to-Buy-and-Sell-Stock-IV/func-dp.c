//same idea as 188-Best-Time-to-Buy-and-Sell-Stock-III
#define max(a,b) ((a)>(b)?a:b)

int maxProfit(int k, int* prices, int pricesSize) {
    int dp[pricesSize][k*2];
    for(int j = 0; j < k; j++) {
        dp[0][2*j] = -prices[0];    // hold
        dp[0][2*j+1] = 0;           // unhold
    }

    for (int i = 1; i < pricesSize; i++) {
        for (int j = 0; j < k; j++) {         
            dp[i][2*j] = max(dp[i-1][2*j], j == 0 ? -prices[i] : dp[i-1][2*j-1]-prices[i]);
            dp[i][2*j+1] = max(dp[i-1][2*j+1], dp[i][2*j]+prices[i]);
        }
    }
    return dp[pricesSize-1][k*2-1];
}
