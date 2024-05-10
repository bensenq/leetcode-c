
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int *result = malloc(sizeof(int) * numsSize);
    int i, evenIndex, oddIndex;
    *returnSize = numsSize;
    evenIndex = 0;
    oddIndex = numsSize - 1;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] & 1) {
            result[oddIndex--] = nums[i];
        } else {
            result[evenIndex++] = nums[i];
        }
    }
    return result;
}