/* binary search */
int findMin(int* nums, int numsSize) {
    int ans;
    int n = numsSize;
    if (n == 1) return nums[0];
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        if (nums[left] <= nums[right]) {
            ans = nums[left];
            break;
        }
        mid = (left + right) / 2;
        if (nums[left] > nums[mid]) {
            right = mid;
        } else if (nums[left] <= nums[mid]) {
            left = mid + 1;
        }
    }
    return ans;
}