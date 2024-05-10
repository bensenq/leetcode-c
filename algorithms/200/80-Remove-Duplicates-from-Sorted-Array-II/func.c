int removeDuplicates(int* nums, int numsSize){
    int i = 1, j = 1;
    int last = nums[0];
    int repeat = 0;
    while (i < numsSize) {
        if (nums[i] == last) {
            if (repeat == 0) {
                nums[j] = nums[i];
                repeat = 1;
                j++;
            }
        } else {
            nums[j] = nums[i];
            j++;
            last = nums[i];
            repeat = 0;
        }
        i++;
    }
    return j;
}