int minimumSum(int* nums, int numsSize) {
    #define MAX 150
    if (numsSize < 3) {
        return -1; // Array length is less than 3, cannot form a triplet
    }

    // Initialize left_min and right_min arrays
    int left_min[numsSize];
    int right_min[numsSize];

    // Fill the left_min array
    left_min[0] = MAX; // No element to the left of the first element
    for (int i = 1; i < numsSize; i++) {
        left_min[i] = (left_min[i - 1] < nums[i - 1]) ? left_min[i - 1] : nums[i - 1];
    }

    // Fill the right_min array
    right_min[numsSize - 1] = INT_MAX; // No element to the right of the last element
    for (int i = numsSize - 2; i >= 0; i--) {
        right_min[i] = (right_min[i + 1] < nums[i + 1]) ? right_min[i + 1] : nums[i + 1];
    }

    // Find the minimum sum of mountain triplets
    int min_sum = MAX;
    for (int j = 1; j < numsSize - 1; j++) {
        if (nums[j] > left_min[j] && nums[j] > right_min[j]) {
            int current_sum = left_min[j] + nums[j] + right_min[j];
            if (current_sum < min_sum) {
                min_sum = current_sum;
            }
        }
    }

    // Return the result
    return (min_sum != MAX) ? min_sum : -1;
}