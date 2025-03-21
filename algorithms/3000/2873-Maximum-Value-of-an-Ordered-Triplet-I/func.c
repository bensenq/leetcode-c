long long maximumTripletValue(int* nums, int numsSize) {
    if (numsSize < 3) return 0; // If the array length is less than 3, return 0 directly

    // Arrays to store the maximum and minimum values to the right of each position
    int maxRight[numsSize];
    int minRight[numsSize];

    // Initialize the maximum and minimum values to the right
    maxRight[numsSize - 1] = nums[numsSize - 1];
    minRight[numsSize - 1] = nums[numsSize - 1];

    // Fill the maxRight and minRight arrays
    for (int i = numsSize - 2; i >= 0; i--) {
        maxRight[i] = (nums[i] > maxRight[i + 1]) ? nums[i] : maxRight[i + 1];
        minRight[i] = (nums[i] < minRight[i + 1]) ? nums[i] : minRight[i + 1];
    }

    long long maxVal = 0; // Variable to store the maximum value

    // Iterate through all possible triplets (i, j, k)
    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i + 1; j < numsSize - 1; j++) {
            long long diff = nums[i] - nums[j];
            if (diff > 0) {
                // If nums[i] - nums[j] > 0, try to calculate with the maximum value to the right
                if (maxRight[j + 1] > 0) {
                    long long value = diff * maxRight[j + 1];
                    if (value > maxVal) {
                        maxVal = value;
                    }
                }
            } else {
                // If nums[i] - nums[j] < 0, try to calculate with the minimum value to the right
                if (minRight[j + 1] < 0) {
                    long long value = diff * minRight[j + 1];
                    if (value > maxVal) {
                        maxVal = value;
                    }
                }
            }
        }
    }

    return maxVal; // Return the maximum value
}