//sliding window
int minimumSumSubarray(int* nums, int numsSize, int l, int r) {
    int ans = INT_MAX, n = numsSize;
    int initial_sum = 0;
    for(int i = 0; i < l-1; i++) {
        initial_sum += nums[i];
    }
    for(int i = l; i <= r; i++) {
        initial_sum += nums[i-1];
        int sum = initial_sum;
        if(sum > 0 && sum < ans) {
            ans = sum;
        }
        int s = 0, e = i - 1;
        while(e < n - 1) {            
            sum -= nums[s];
            s++;
            e++;
            sum += nums[e];
            if (sum > 0 && sum < ans) {
                ans = sum;
            }
        }
    }
    if(ans == INT_MAX) ans = -1;
    return ans;
}
