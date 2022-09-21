bool biSearch(int *nums, int numsSize, int target) {

    if (numsSize == 0) return false;
    if (target == nums[0] || target == nums[numsSize-1]) return true;
    if (target < nums[0] || target > nums[numsSize-1]) return false;
    
    int left = 0, right = numsSize - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (target == nums[mid])
            return true;
        else if(target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;    
        }
    }
    return false;
}

bool search(int* nums, int numsSize, int target) {
    int i = 1;
    while(i < numsSize) {
        if (nums[i] < nums[i-1])
            break;
        i++;
    }
    
    return biSearch(nums, i, target) || biSearch(nums+i, numsSize-i, target);
}