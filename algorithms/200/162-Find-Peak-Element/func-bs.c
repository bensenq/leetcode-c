int findPeakElement(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1, mid;
    int ans;
    while (left <= right) {
        mid = (left + right) / 2;
        if ((mid == 0 || nums[mid] > nums[mid-1])
        && (mid == numsSize -1 || nums[mid] > nums[mid+1])) {
            ans = mid;
            break;
        } else if (mid != 0 && nums[mid] < nums[mid-1]) {
            right = mid - 1;
        } else if (mid != numsSize -1 && nums[mid] < nums[mid+1]) {
            left = mid + 1;
        }
    }
    return ans;
}