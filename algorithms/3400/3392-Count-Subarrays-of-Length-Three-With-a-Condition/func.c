int countSubarrays(int* nums, int numsSize) {
    int result = 0;
    for (int i = 2; i < numsSize; i++) {
        if ((nums[i-2]+nums[i])*2 == nums[i-1])
            result++;
    }
    return result;
}
