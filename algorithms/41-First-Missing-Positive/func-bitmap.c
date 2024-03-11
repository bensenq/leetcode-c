//bitmap solution
int firstMissingPositive(int* nums, int numsSize) {
    unsigned long long *bitmap = calloc(8, (numsSize/64 + 1));
    int i = 0, j = 0;
    while(i < numsSize) {
        if (nums[i] > 0 && nums[i] <= numsSize) {
            bitmap[(nums[i]-1)/64] |= 1ULL << (nums[i]-1)%64;
        }
        i++;
    }
    for (i = 0; i < numsSize/64 + 1; i++) {
        if (bitmap[i] != 0xFFFFFFFFFFFFFFFF) {
            for(j = 0; j < 64; j++) {
                if((bitmap[i] & (1ULL << j)) == 0) {
                    goto out;
                }
            }
        }
    }
out:
    return i*64 + j + 1; 
}