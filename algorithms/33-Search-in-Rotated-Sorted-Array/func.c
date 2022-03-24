

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } 
        
        if (nums[left] <= nums[mid] && 
            (target >= nums[left] && target <= nums[mid])) {
            right = mid;
        } else if (nums[mid+1] <= nums[right] &&
            (target >= nums[mid+1] && target <= nums[right])) {
            left = mid + 1;
        } else if (nums[left] >= nums[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return nums[left] == target ? left : -1;
    
}
