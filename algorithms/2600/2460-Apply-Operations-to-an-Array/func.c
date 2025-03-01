/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize) {
    int *result = calloc(sizeof(int), numsSize);
    int last = nums[0];
    int i, j;
    for (i = 0, j = 0; i+1 < numsSize; i++) {
        if (last == 0) {
            last = nums[i+1];
        } else if (last == nums[i+1]) {
            result[j] = last * 2;
            last = 0;
            j++;
        } else {
            result[j] = last;
            last = nums[i+1];
            j++;
        }
    }
    result[j] = last;
    *returnSize = numsSize;
    return result;
}