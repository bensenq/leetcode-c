int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    int i = 1;
    while (i < pricesSize) {
        if (prices[i] > prices[i-1])
            maxProfit += prices[i] - prices[i-1];
        i++;
    }
    return maxProfit;    
}