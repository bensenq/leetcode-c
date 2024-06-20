int minEatingSpeed(int* piles, int pilesSize, int h) {
    int max, min, mid;
    int ans;
    int total;
    long long sum = 0;
    max = 0;
    for (int i = 0; i < pilesSize; i++) {
        sum += piles[i];
        if (piles[i] > max) max = piles[i];
    }
    min = sum % h == 0 ? (sum / h) : (sum / h + 1);
    while (min <= max) {
        mid = (min + max) / 2;
        total = 0;
        for (int i = 0; i < pilesSize; i++) {
            // printf("min:%d, max:%d, mid:%\d\n", min, max, mid);
            total += piles[i] % mid == 0 ? (piles[i] / mid) : (piles[i] / mid + 1);
        }
        if (total > h) {
            min = mid + 1;
        } else {
            ans = mid;
            max = mid - 1;
        }
    }
    return ans; 
}