int maximumCandies(int* candies, int candiesSize, long long k) {
    long long total = 0;

    // Calculate the total number of candies
    for (int i = 0; i < candiesSize; i++) {
        total += candies[i];
    }

    // If the total number of candies is less than k, allocation is impossible
    if (total < k) {
        return 0;
    }

    // Binary search range
    int left = 1;
    int right = total / k; // Maximum possible candies per child
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevent overflow
        long long piles = 0;

        // Calculate the number of piles that can be formed with the current mid
        for (int i = 0; i < candiesSize; i++) {
            piles += candies[i] / mid;
        }

        // Check if the condition is satisfied
        if (piles >= k) {
            result = mid;       // Update the result
            left = mid + 1;     // Try a larger value
        } else {
            right = mid - 1;    // Try a smaller value
        }
    }

    return result;
}