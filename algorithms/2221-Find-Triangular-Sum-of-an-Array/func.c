int triangularSum(int* nums, int numsSize) {
    int i = numsSize;
    int result;
    while (i > 1) {
        for (int j = 0; j < i-1; j++) {
            nums[j] = (nums[j] + nums[j+1]) % 10;
        }
        i--;
    }
    return nums[0];      
}