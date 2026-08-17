//DP：rolling array
#define max(x, y) (x > y ? x : y)

int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len1 = nums1Size, len2 = nums2Size;
    int prev_row[len2 + 1];
    int cur_row[len2 + 1];
    int *prev = prev_row;
    int *cur = cur_row;

    for (int j = 0; j <= len2; j++) prev[j] = 0;

    for (int i = 1; i <= len1; i++) {
        cur_row[0] = 0;
        for (int j = 1; j <= len2; j++) {
            if (nums1[i-1] == nums2[j-1]) {
                cur[j] = prev[j-1] + 1;
            } else {
                cur[j] = max(prev[j], cur[j-1]);
            }
        }
        int *tmp = prev;
        prev = cur;
        cur = tmp;
    }
    return prev[len2];    
}
