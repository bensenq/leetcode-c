/* binary search */
long long repairCars(int* ranks, int ranksSize, int cars) {
    int min = ranks[0];
    for (int i = 1; i < ranksSize; i++) {
        if (ranks[i] < min) min = ranks[i];
    }
    long long low = 1, high = 1LL * cars * cars * min;
    // Perform binary search to find the minimum time required.
    while (low < high) {
        long long mid = low + (high - low) / 2, carsRepaired = 0;

        // Calculate the number of cars that can be repaired in 'mid' time
        // by all mechanics.
        for (int i = 0; i < ranksSize; i++) carsRepaired += sqrt(1.0 * mid / ranks[i]);

        // If the total cars repaired is less than required, increase the
        // time.
        if (carsRepaired < cars)
            low = mid + 1;
        else
            high = mid;  // Otherwise, try a smaller time.
    }
    return low;
}