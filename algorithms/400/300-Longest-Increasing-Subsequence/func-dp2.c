#define max(x, y) x > y ? x : y

int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize+1];
    int ans = 1;
    dp[1] = 1;
    for (int i = 2; i <= numsSize; i++) {
        dp[i] = 1;
        for(int j = 1; j < i; j++) {
            if (nums[j-1] < nums[i-1])
            dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
