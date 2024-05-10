int removeDuplicates(int* nums, int numsSize){
    int i = 0, j = 0;
    int last = -200; 
    while(j < numsSize) {
        if (nums[j] != last) {
            nums[i] = nums[j];
            last = nums[i];
            i++;
        }
        j++;
    }
    return i;
}