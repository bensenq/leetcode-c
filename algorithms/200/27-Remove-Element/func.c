int removeElement(int* nums, int numsSize, int val){
    int i = 0, j = 0;
    while(j < numsSize) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    return i;
}