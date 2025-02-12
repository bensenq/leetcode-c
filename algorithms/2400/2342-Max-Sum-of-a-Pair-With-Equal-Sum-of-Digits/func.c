#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SUM 100 // maximum sum of digits is 99

// Define the hash table entry structure
typedef struct {
    int first;  // The largest number
    int second; // The second largest number
} HashEntry;

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int maximumSum(int* nums, int numsSize) {
    HashEntry* hashMap = (HashEntry*)calloc(MAX_SUM, sizeof(HashEntry));
    int maxSum = -1; // Initialize the maximum sum as -1 (indicating no valid pair found)

    for (int i = 0; i < numsSize; i++) {
        int key = sumOfDigits(nums[i]);
        int updated = 0;

        // Update the largest and second largest values for the current key
        if (nums[i] > hashMap[key].first) {
            hashMap[key].second = hashMap[key].first;
            hashMap[key].first = nums[i];
            updated = 1;
        } else if (nums[i] > hashMap[key].second) {
            hashMap[key].second = nums[i];
            updated = 1;
        }

        if (updated && hashMap[key].second != 0) {
            int val = hashMap[key].first + hashMap[key].second;
            if (val > maxSum) {
                maxSum = val;
            }
        }
    }

    free(hashMap);
    return maxSum;
}