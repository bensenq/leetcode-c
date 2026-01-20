#define max(a, b) (a > b ? a : b)
int robOld(int* nums, int numsSize) {
    int dp[numsSize+1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= numsSize; i++) {
        dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
    }
    return dp[numsSize];
}
int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    int notRobLast = robOld(nums, numsSize-1);
    int notRobFirst = robOld(nums+1, numsSize-1);
    return max(notRobLast, notRobFirst);
}