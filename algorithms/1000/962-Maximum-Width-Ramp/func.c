int maxWidthRamp(int* nums, int numsSize) {
    int rmax[numsSize];
    int max = INT_MIN;
    for (int i = numsSize-2; i >= 0; i--) {
        if (nums[i+1] > max) {
            rmax[i] = nums[i+1];
            max = nums[i+1];
        } else {
            rmax[i] = max;
        }
    }

    int ans = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (rmax[i] < nums[i]) continue;
        if (numsSize-1-i <= ans) break;
        for (int j = numsSize-1; j > i; j--) {
            if (j - i < ans) break;
            if (nums[j] >= nums[i]) {
                ans = j - i;
                break;
            }
        }
    }
    return ans;
}