//DP: 1-Dimension Version
#define max(x, y) (x > y ? x : y)

int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len1 = nums1Size, len2 = nums2Size;
    int dp[len2 + 1];   

    for (int j = 0; j <= len2; j++) dp[j] = 0;

    for (int i = 1; i <= len1; i++) {
        // prev for up-left (dp[i-1][j-1])，init.  dp[i-1][0]
        int prev = dp[0];
        dp[0] = 0;
        for (int j = 1; j <= len2; j++) {
            // temp for up(dp[i-1][j]) and it's also next up-left (dp[i-1][j+1-1])
            int temp = dp[j];
            if (nums1[i-1] == nums2[j-1]) {
                dp[j] = prev + 1;
            } else {
                dp[j] = max(temp, dp[j-1]);
            }
            prev = temp;
        }
    }
    return dp[len2];    
}
