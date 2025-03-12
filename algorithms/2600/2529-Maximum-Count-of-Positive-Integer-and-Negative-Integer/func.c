// binary search: error-prone
int maximumCount(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1, mid;
    int firstgreater = -1, lastless = -1;
    int greater, less;
    // find first element greater than 0
    while(left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] <= 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (left < numsSize && nums[left] > 0) firstgreater = left;
    
    // find last element less than 0
    left = 0, right = numsSize - 1;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (right >= 0 && nums[right] < 0) lastless = right;

    if (firstgreater == -1) {
        greater = 0;
    } else {
        greater = numsSize - firstgreater;
    }

    if (lastless == -1) {
        less = 0;
    } else {
        less = lastless + 1;
    }

    return fmax(greater, less); 
}