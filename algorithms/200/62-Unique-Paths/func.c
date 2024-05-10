// it's a math problem

long C(int n, int k) {
    if (k > n/2) k = n - k;
    long result = 1;
    for (int i = 1; i <= k; i++) {
        result = result*(n-k+i)/i;
    }
    return result;
}

int uniquePaths(int m, int n){
    return C(m+n-2, n-1);
}