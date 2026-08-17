//DP: 2D version
#define max(x, y) (x > y ? x : y)

int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len1 = nums1Size, len2 = nums2Size;
    int dp[len1+1][len2+1];
    int t;
    for (int i = 0; i <= len1; i++) dp[i][0] = 0;
    for (int j = 0; j <= len2; j++) dp[0][j] = 0;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (nums1[i-1] == nums2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];    
}
