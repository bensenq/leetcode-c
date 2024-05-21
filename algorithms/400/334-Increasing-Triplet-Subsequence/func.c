bool increasingTriplet(int* nums, int numsSize) {
    bool ans = false;
    int n = numsSize;
    int *minLeft = malloc(sizeof(int) * n);
    int *maxRight = malloc(sizeof(int) * n);
    minLeft[0] = nums[0];
    maxRight[n-1] = nums[n-1];
    for (int i = 1; i < n; i++) {
        if (nums[i] < minLeft[i-1]) minLeft[i] = nums[i]; else minLeft[i] = minLeft[i-1];
        if (nums[n-1-i] > maxRight[n-i]) maxRight[n-1-i] = nums[n-1-i]; else maxRight[n-1-i] = maxRight[n-i];
    }
    for (int i = 1; i < n - 1; i++) {
        if (nums[i] > minLeft[i-1] && nums[i] < maxRight[i+1]) {
            ans = true;
            break;
        }
    }
    free(minLeft);
    free(maxRight);
    return ans;
}
