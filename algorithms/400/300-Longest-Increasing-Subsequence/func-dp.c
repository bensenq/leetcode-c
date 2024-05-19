// Dynamic Programming Solution
// ref: https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326552/optimization-from-brute-force-to-dynamic-programming-explained/
/* 
 * For each element nums[i], if there's an smaller element nums[j] before it, 
 * the result will be maximum of current LIS length ending at i: dp[i], and 
 * LIS ending at that j + 1: dp[j] + 1. +1 because we are including the current 
 * element and extending the LIS ending at j.
 */

#define max(a,b) (a>b?a:b)
int lengthOfLIS(int* nums, int numsSize) {
    int ans = 1;
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) dp[i] = 1;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
}