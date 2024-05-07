int findMaxK(int* nums, int numsSize) {
    int result = -1;
    int index, offset;
    long long *bitmap = calloc(sizeof(long long) * 2001 / 64 * 8, 1);
    for (int i = 0; i < numsSize; i++) {
        index = (nums[i] + 1000) / 64;
        offset = (nums[i] + 1000) % 64;
        if ((bitmap[index] & (1ULL << offset)) == 0) {
            bitmap[index] |= 1ULL << offset;
        }        
        index = (-nums[i] + 1000) / 64;
        offset = (-nums[i] + 1000) % 64;
        if ((bitmap[index] & (1ULL << offset)) != 0) {
            if(abs(nums[i]) > result) result = abs(nums[i]); 
        }
    }
    free(bitmap);
    return result;
}