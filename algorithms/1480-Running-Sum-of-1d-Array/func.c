
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int * result = malloc(sizeof(int) * numsSize);
    int sum = 0, i = 0;
    while (i < numsSize) {
        sum += nums[i];
        result[i] = sum;
        i++;
    }
    *returnSize = numsSize;
    return result;
}