int countPrimes(int n) {
    bool *notPrime = calloc(sizeof(bool), n);
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (notPrime[i] == false) {
            count++;
            for (int j = 2; i*j < n; j++) {
                notPrime[i*j] = true;
            }
        }
    }
    return count;
}
