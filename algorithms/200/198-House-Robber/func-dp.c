#define max(a, b) (a > b ? a : b)
int rob(int* nums, int numsSize) {
    int dp[numsSize+1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= numsSize; i++) {
        dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
    }
    return dp[numsSize];
}