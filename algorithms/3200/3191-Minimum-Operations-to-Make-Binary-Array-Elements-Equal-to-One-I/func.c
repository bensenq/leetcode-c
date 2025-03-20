int minOperations(int* nums, int numsSize) {
    int count = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            if (i + 2 >= numsSize) {
                count = -1;
                break;
            }
            // Flip the current and next two elements
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
            count++;
        }
    }

    return count;
}