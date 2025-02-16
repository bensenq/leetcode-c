// Function to check if a number can be placed at the given index
int canPlace(int *sequence, int size, int num, int index) {
    if (num > 1 && (index + num >= size || sequence[index + num] != 0)) {
        return 0;
    }
    return 1;
}

// Recursive function to generate the sequence
int generateSequence(int *sequence, int size, int *used, int n, int currentIndex) {
    while (currentIndex < size && sequence[currentIndex] != 0) {
        currentIndex++;
    }

    if (currentIndex >= size) {
        return 1; // All positions are filled successfully
    }

    for (int num = n; num >= 1; num--) { // Try placing the largest unused number
        if (!used[num]) {
            if (canPlace(sequence, size, num, currentIndex)) {
                sequence[currentIndex] = num;
                used[num] = 1;
                if (num != 1) {
                    sequence[currentIndex + num] = num;
                }

                if (generateSequence(sequence, size, used, n, currentIndex + 1)) {
                    return 1;
                }

                // Backtrack
                sequence[currentIndex] = 0;
                used[num] = 0;
                if (num != 1) {
                    sequence[currentIndex + num] = 0;
                }
            }
        }
    }
    return 0; // No valid placement found for this position
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructDistancedSequence(int n, int* returnSize) {
    int size = n*2-1;
    int *res = calloc(sizeof(int), size);
    int *used = calloc(n + 1, sizeof(int));
    generateSequence(res, size, used, n, 0);
    *returnSize = size;
    return res;
}