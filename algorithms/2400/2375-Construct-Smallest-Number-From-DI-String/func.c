#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_LENGTH 10

// Backtracking function to find the smallest valid number
bool backtrack(char* pattern, int* num, int len, bool* used) {
    int n = strlen(pattern) + 1;
    if (len == n) {
        // Found the smallest valid number
        return true;
    }

    char nextPattern = pattern[len - 1];
    for (int digit = 1; digit <= 9; digit++) {
        if (!used[digit]) {
            if (len == 0 || (nextPattern == 'I' && digit > num[len - 1]) || (nextPattern == 'D' && digit < num[len - 1])) {
                num[len] = digit;
                used[digit] = true;
                if (backtrack(pattern, num, len + 1, used)) {
                    return true;
                }
                used[digit] = false;
            }
        }
    }
    return false; // No valid number found
}

char* smallestNumber(char* pattern) {
    int n = strlen(pattern) + 1;
    int* num = (int*)malloc(n * sizeof(int)); // Temporary array to store the number sequence
    bool* used = (bool*)calloc(10, sizeof(bool)); // Track used digits
    char* result = NULL;

    // First digit should be from 1 to 9
    for (int firstDigit = 1; firstDigit <= 9; firstDigit++) {
        num[0] = firstDigit;
        used[firstDigit] = true;
        if (backtrack(pattern, num, 1, used)) {
            // Convert the number array to a string
            result = (char*)malloc((n + 1) * sizeof(char));
            for (int i = 0; i < n; i++) {
                result[i] = num[i] + '0';
            }
            result[n] = '\0';
            break; // Found the smallest valid number
        }
        used[firstDigit] = false;
    }

    free(num);
    free(used);
    return result;
}