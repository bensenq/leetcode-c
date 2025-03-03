/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int i = 0, j = 0;
    int pcount = 0;
    int *result = malloc(sizeof(int) * numsSize);
    while(i < numsSize) {
        if (nums[i] < pivot)
            result[j++] = nums[i];
        else if (nums[i] == pivot) pcount++;
        i++;
    }

    i = 0;
    while(i < pcount) {
        result[j++] = pivot;
        i++;
    }

    i = numsSize - 1; j = numsSize - 1;
    while(i >= 0) {
        if (nums[i] > pivot)
            result[j--] = nums[i];
        i--;       
    }

    *returnSize = numsSize;
    return result;
}