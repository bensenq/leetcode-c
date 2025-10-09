#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    char *concat1 = malloc(strlen(str1) + strlen(str2) + 1);
    char *concat2 = malloc(strlen(str2) + strlen(str1) + 1);
    strcpy(concat1, str1);
    strcat(concat1, str2);
    strcpy(concat2, str2);
    strcat(concat2, str1);
    int result = strcmp(concat2, concat1);
    free(concat1);
    free(concat2);
    return result;
}

char *largestNumber(int *nums, int numsSize) {
    char **strs = malloc(numsSize * sizeof(char *));
    for (int i = 0; i < numsSize; i++) {
        strs[i] = malloc(11 * sizeof(char));
        sprintf(strs[i], "%d", nums[i]);
    }
    qsort(strs, numsSize, sizeof(char *), compare);
    if (strcmp(strs[0], "0") == 0) {
        return "0";
    }
    char *result = malloc(1001 * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strs[i]);
    }
    return result;
}
