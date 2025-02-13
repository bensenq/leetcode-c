#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int heightChecker(int* heights, int heightsSize) {
    int expected[heightsSize];
    for (int i = 0; i < heightsSize; i++) {
        expected[i] = heights[i];
    }

    qsort(expected, heightsSize, sizeof(int), compare);

    int count = 0;
    for (int i = 0; i < heightsSize; i++) {
        if (heights[i] != expected[i]) {
            count++;
        }
    }

    return count;
}