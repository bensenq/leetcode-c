bool check(int* nums, int numsSize){
    int i;
    int smallest = nums[0];
    i = 1;
    while (i < numsSize) {
        if (nums[i] >= nums[i-1])
            i++;
        else
            break;
    }
    
    if (i == numsSize)
        return true;
    
    if (nums[i] > smallest)
        return false;
    
    i++;
    while(i < numsSize) {
        if (nums[i] >= nums[i-1])
            i++;
        else
            return false;
    }
    if (nums[numsSize-1] <= smallest)
        return true;
    else
        return false;
}