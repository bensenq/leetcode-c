int countTriples(int n) {
    int count = 0;
    int max = ceil(n/sqrt(2));
    for (int i = 1; i <= max; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = i*i + j*j;
            if (x > n*n) break;
            int k = sqrt(x);
            if(i*i + j*j == k*k) {
                count++;
            }
        }
    }
    return count*2;    
}