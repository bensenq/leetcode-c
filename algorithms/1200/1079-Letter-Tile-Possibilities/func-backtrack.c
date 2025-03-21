#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Iterative calculation of factorial
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Calculate permutations of a multiset
int multisetPermutations(int *freq, int len) {
    int total = 0;
    for (int i = 0; i < len; ++i) {
        total += freq[i];
    }

    int result = factorial(total);
    for (int i = 0; i < len; ++i) {
        result /= factorial(freq[i]);
    }
    return result;
}

// Recursive function to generate all possible subsets and calculate their permutations
void generateSubsets(int pos, int *freq, int *currentSubset, int len, int *result) {
    if (pos == len) {
        // Calculate permutations of the current subset and add to the result
        *result += multisetPermutations(currentSubset, len);
        return;
    }

    // Do not select the current character
    generateSubsets(pos + 1, freq, currentSubset, len, result);

    // Select the current character (from 1 to freq[pos] times)
    for (int i = 1; i <= freq[pos]; ++i) {
        currentSubset[pos] = i;
        generateSubsets(pos + 1, freq, currentSubset, len, result);
    }
    currentSubset[pos] = 0; // Backtrack
}

// Function to count the number of tile possibilities
int numTilePossibilities(char *tiles) {
    int freq[26] = {0}; // Assume only uppercase letters
    int uniqueChars = 0;

    // Count the frequency of each character
    for (int i = 0; tiles[i] != '\0'; ++i) {
        if (freq[tiles[i] - 'A'] == 0) {
            uniqueChars++;
        }
        freq[tiles[i] - 'A']++;
    }

    // Create arrays to store the frequencies of unique characters
    int *uniqueFreq = (int *)malloc(uniqueChars * sizeof(int));
    int *currentSubset = (int *)malloc(uniqueChars * sizeof(int));

    int index = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) {
            uniqueFreq[index] = freq[i];
            currentSubset[index] = 0;
            index++;
        }
    }

    int result = 0;
    generateSubsets(0, uniqueFreq, currentSubset, uniqueChars, &result);

    free(uniqueFreq);
    free(currentSubset);

    // Subtract the empty set case
    return result - 1;
}