int findDuplicate(int* nums, int numsSize){
    unsigned long long *bitmap = calloc((numsSize+1)/64 + 1, 8);
    unsigned long long bitshift;
    int i = 0;
    int index;
    while (i < numsSize) {
        index = nums[i]/64;
        bitshift = 1ULL<<(nums[i]%64);
        if (bitmap[index] & bitshift)
            break;
        else 
            bitmap[index] |= bitshift;
        i++;
    }
    free(bitmap);
    return nums[i];
}