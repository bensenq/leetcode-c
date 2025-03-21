// Convert a binary string to an integer
int binaryStringToInt(const char* str) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        result = result * 2 + (str[i] - '0');
    }
    return result;
}

// Convert an integer to a binary string of length n
void intToBinaryString(int num, int n, char* result) {
    for (int i = n - 1; i >= 0; i--) {
        result[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    result[n] = '\0'; // Add the string terminator
}

// Main function
char* findDifferentBinaryString(char** nums, int numsSize) {
    int n = numsSize; // Length of each binary string
    int maxNum = 1 << n; // 2^n, the maximum number that can be represented
    int* hashtable = (int*)calloc(maxNum, sizeof(int)); // Create a hash table initialized to 0

    // Iterate through the input strings and mark the numbers that have appeared
    for (int i = 0; i < numsSize; i++) {
        int num = binaryStringToInt(nums[i]);
        hashtable[num] = 1; // Mark as appeared
    }

    // Find the first number that has not appeared
    int absentNum = -1;
    for (int i = 0; i < maxNum; i++) {
        if (hashtable[i] == 0) {
            absentNum = i;
            break;
        }
    }

    // Convert the absent number to a binary string
    char* result = (char*)malloc((n + 1) * sizeof(char)); // Allocate memory
    intToBinaryString(absentNum, n, result);

    // Free the hash table memory
    free(hashtable);

    return result;
}