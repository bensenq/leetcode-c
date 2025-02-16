// Helper function to check if the square of a number can be partitioned into substrings that sum up to the number
int canPartition(int target, char *str, int index) {
    if (index == strlen(str)) {
        return target == 0;
    }

    int current = 0;
    for (int i = index; i < strlen(str); i++) {
        current = current * 10 + (str[i] - '0');
        if (current > target) {
            break;
        }
        if (canPartition(target - current, str, i + 1)) {
            return 1;
        }
    }
    return 0;
}

// Function to calculate the punishment number of n
int punishmentNumber(int n) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        int square = i * i;
        char str[20]; // Buffer to hold the string representation of the square
        sprintf(str, "%d", square);

        if (canPartition(i, str, 0)) {
            result += square;
        }
    }

    return result;
}