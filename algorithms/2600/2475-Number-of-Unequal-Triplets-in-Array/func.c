#define MAX_NUM 1001

int unequalTriplets(int* nums, int numsSize) {
    int count[MAX_NUM] = {0}; // Array to record the frequency of each number
    int distinctCount = 0;
    int result = 0;           // Variable to store the number of valid triplets


    // Count the frequency of each number in the array
    for (int i = 0; i < numsSize; i++) {
        if (count[nums[i]] == 0) {
            distinctCount++;
        }
        count[nums[i]]++;
    }

    int j = 0;

    // Compress the count array by recording the indices of non-zero elements
    for (int i = 0; i < MAX_NUM; i++) {
        if (count[i] > 0) {
            count[j++] = count[i]; // Record the index of non-zero elements
        }
        if (j == distinctCount) break;
    }

    // Calculate the number of valid triplets
    for (int i = 0; i < distinctCount; i++) {
        for (int j = i + 1; j < distinctCount; j++) {
            for (int k = j + 1; k < distinctCount; k++) {
                // For each unique triplet (i, j, k), calculate the number of combinations
                result += count[i] * count[j] * count[k];
            }
        }
    }

    return result;
}