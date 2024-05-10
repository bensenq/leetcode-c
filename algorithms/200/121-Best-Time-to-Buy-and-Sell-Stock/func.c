int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    int minHistory = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > minHistory) {
            if (prices[i] - minHistory > maxProfit)
                maxProfit = prices[i] - minHistory;
        } else if (prices[i] < minHistory) {
            minHistory = prices[i];
        }
    }
    return maxProfit;
}