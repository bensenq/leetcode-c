#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;
    qsort(nums, numsSize, sizeof(int), compare); // Sort the array

    int ops = 0, last = nums[0]; // Initialize operations counter and last value
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= last) {
            ops += last - nums[i] + 1; // Calculate and accumulate increments
            last += 1;
        } else {
            last = nums[i];
        }
    }
    return ops;
}