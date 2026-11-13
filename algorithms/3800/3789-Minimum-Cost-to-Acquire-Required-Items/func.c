long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long total, price, min, max;
    if(need1 > need2) {
        max = need1;
        min = need2;
        price = cost1;
    } else {
        min = need1;
        max = need2;
        price = cost2;
    }
    if(costBoth < cost1+cost2) {
        total = (long long)costBoth * min;
        if(price > costBoth) {
            total += (long long)costBoth * (max-min);
        } else {
            total += (long long)price * (max-min);
        }
    } else {
        total = (long long)cost1*need1 + (long long)cost2*need2;
    }
    return total;
}
