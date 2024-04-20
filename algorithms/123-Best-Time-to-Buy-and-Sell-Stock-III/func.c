int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;
    int maxProfitLeft[pricesSize];
    int maxProfitRight[pricesSize];
    int minHistory = prices[0];
    maxProfitLeft[0] = 0;
    for (int i = 1; i < pricesSize; i++) {
        maxProfitLeft[i] = maxProfitLeft[i-1];
        if (prices[i] > minHistory) {
            if (prices[i] - minHistory > maxProfitLeft[i-1]) {
                maxProfitLeft[i] = prices[i] - minHistory;
            }
        } else if (prices[i] < minHistory) {
            minHistory = prices[i];
        }
    }    

    int maxFuture = prices[pricesSize-1];
    maxProfitRight[pricesSize-1] = 0;
    for (int i = pricesSize-2; i >= 0; i--) {
        maxProfitRight[i] = maxProfitRight[i+1];
        if (prices[i] < maxFuture) {
            if (maxFuture - prices[i] > maxProfitRight[i+1]) {
                maxProfitRight[i] = maxFuture - prices[i];
            }
        } else if (prices[i] > maxFuture) {
            maxFuture = prices[i];
        }
    }   

    for (int i = 0; i < pricesSize; i++) {
        int t = maxProfitLeft[i] + maxProfitRight[i];
        if (t > maxProfit) maxProfit = t;
    }

    return maxProfit;
}

int main() {
    int prices[] = {1,2,4,2,5,7,2,4,9,0};
    return maxProfit(prices, 10);
}
