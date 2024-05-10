int searchInsert(int* nums, int numsSize, int target){
    int start, end, mid;
    int ret;
    if (target < nums[0])
        return 0;
    if (target > nums[numsSize - 1])
        return numsSize;
    
    start = 0;
    end = numsSize - 1;
    while (start < end) {
        mid = (start + end) / 2;
        if (nums[mid] < target) {
            start = mid + 1;
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            return mid ;
        }
    }
    if (nums[start] < target)
        return start + 1;
    else 
        return start;
}