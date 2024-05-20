// Binary Search Solution
// https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn/

int lengthOfLIS(int* nums, int numsSize) {
    int *lts = malloc(sizeof(int) * numsSize);
    int len = 1;
    lts[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == lts[len-1]) continue;
        if (nums[i] > lts[len-1]) {
            lts[len] = nums[i];
            len++;
        } else {    //do binary search and replace
            int left = 0, right = len - 1, mid;
            while(left <= right) {
                mid = (left + right) / 2;
                if (lts[mid] >= nums[i]) {
                    if (mid == 0 || lts[mid - 1] < nums[i])
                        break;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            lts[mid] = nums[i];
        }
    }
    free(lts);
    return len;
}