//Editorial: 2-Dimention DP with two-pointer

int lenLongestFibSubseq(int* arr, int arrSize) {
    int n = arrSize;
    // dp[prev][curr] stores length of Fibonacci sequence ending at indexes
    // prev,curr
    int **dp = calloc(sizeof(int*), n);
    for (int i = 0; i < n; i++) dp[i] = calloc(sizeof(int), n);
    int maxLen = 0;

    // Find all possible pairs that sum to arr[curr]
    for (int curr = 2; curr < n; curr++) {
        // Use two pointers to find pairs that sum to arr[curr]
        int start = 0;
        int end = curr - 1;

        while (start < end) {
            int pairSum = arr[start] + arr[end];

            if (pairSum > arr[curr]) {
                end--;
            } else if (pairSum < arr[curr]) {
                start++;
            } else {
                // Found a valid pair, update dp
                dp[end][curr] = dp[start][end] + 1;
                maxLen = fmax(dp[end][curr], maxLen);
                end--;
                start++;
            }
        }
    }
    for (int i = 0; i < n; i++) free(dp[i]);
    free(dp);
    // Add 2 to include first two numbers, or return 0 if no sequence found
    return maxLen == 0 ? 0 : maxLen + 2;    
}