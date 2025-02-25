int findMin(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        // If the middle element is less than the rightmost element,
        // the minimum value must be in the left half (including mid).
        if (nums[mid] < nums[right]) {
            right = mid;
        }
        // If the middle element is greater than the rightmost element,
        // the minimum value must be in the right half (excluding mid).
        else if (nums[mid] > nums[right]) {
            left = mid + 1;
        }
        // If the middle element is equal to the rightmost element,
        // we cannot determine the exact half, but we can safely
        // reduce the search space by decrementing the right pointer.
        else {
            right--;
        }
    }

    // When left == right, the element at left is the minimum value.
    return nums[left];
}