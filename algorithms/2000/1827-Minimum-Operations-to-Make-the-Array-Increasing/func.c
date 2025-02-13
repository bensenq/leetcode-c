int minOperations(int* nums, int numsSize){
    int ops = 0;
    int last = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= last) {
            ops += last - nums[i] + 1;
            nums[i] = last + 1;
        } 
        last = nums[i];
    }
    return ops;
}