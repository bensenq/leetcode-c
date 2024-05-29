int pivotIndex(int* nums, int numsSize) {
    int sum = 0, left, right;
    int ans = -1;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    left = 0; right = sum;
    for (int i = 0; i < numsSize; i++) {
        right = right - nums[i];
        if (left == right) return i;
        else {
            left += nums[i];
        }
    }
    return ans;
}