// counting sort
#define MAX_HEIGHT 100
int heightChecker(int* heights, int heightsSize) {
    // Step 1: Use counting sort to count the occurrences of each height
    int count[MAX_HEIGHT + 1] = {0}; // Initialize the count array
    for (int i = 0; i < heightsSize; i++) {
        count[heights[i]]++; // Count the occurrences of each height
    }

    // Step 2: Generate the sorted expected array
    int expected[heightsSize];
    int index = 0;
    for (int h = 1; h <= MAX_HEIGHT; h++) {
        while (count[h] > 0) {
            expected[index++] = h; // Place height h into the expected array
            count[h]--;
        }
    }

    // Step 3: Count the number of mismatched indices
    int mismatch_count = 0;
    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != expected[i]) {
            mismatch_count++;
        }
    }
    return mismatch_count;
}
