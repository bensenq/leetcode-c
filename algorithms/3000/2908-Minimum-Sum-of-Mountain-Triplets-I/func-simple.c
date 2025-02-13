int minimumSum(int* nums, int numsSize) {
    int min = 150;
    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize - 1; j++) {
            if (nums[j] > nums[i]) {
                int sum = nums[j] + nums[i];
                for (int k = j + 1; k < numsSize; k++) {
                    if (nums[k] < nums[j]) {
                        if (sum + nums[k] < min) min = sum + nums[k];
                    }
                }
            }
        }
    }
    if (min == 150) min = -1;
    return min;
}