//prefix sum
int numOfSubarrays(int* arr, int n) {
    const int MOD = 1000000007;
    int odd = 0, even = 1;
    int prefix = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        prefix = (prefix + arr[i]) & 1;
        if (prefix & 1) {
            ans = (ans + even) % MOD;
            odd++;
        } else {
            ans = (ans + odd) % MOD;
            even++;
        }
    }
    return ans;
}
