// Function to calculate the squared distance between two points
int squaredDistance(int* p1, int* p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

// Function to check if four points form a square
bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size) {
    // Array to store the squared distances between all pairs of points
    int distances[6];

    // Calculate all 6 squared distances
    distances[0] = squaredDistance(p1, p2);
    distances[1] = squaredDistance(p1, p3);
    distances[2] = squaredDistance(p1, p4);
    distances[3] = squaredDistance(p2, p3);
    distances[4] = squaredDistance(p2, p4);
    distances[5] = squaredDistance(p3, p4);

    // Find the smallest and largest distances
    int minDist = distances[0];
    int maxDist = distances[0];
    for (int i = 1; i < 6; i++) {
        if (distances[i] < minDist) minDist = distances[i];
        if (distances[i] > maxDist) maxDist = distances[i];
    }

    // Check conditions for a valid square:
    // 1. The smallest distance must appear exactly 4 times (sides).
    // 2. The largest distance must appear exactly 2 times (diagonals).
    // 3. The largest distance must be twice the smallest distance (Pythagorean theorem).
    // 4. The smallest distance must be non-zero (positive side lengths).
    int countMin = 0, countMax = 0;
    for (int i = 0; i < 6; i++) {
        if (distances[i] == minDist) countMin++;
        if (distances[i] == maxDist) countMax++;
    }

    return (countMin == 4 && countMax == 2 && maxDist == 2 * minDist && minDist != 0);
}