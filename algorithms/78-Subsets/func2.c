void genSubset(int *nums, int numsSize, int* data, int pos, int** result, int *resultSize, int *returnColumnSizes) {
    if (numsSize == 0) {
        result[*resultSize] = malloc(sizeof(int)*pos);
        memcpy(result[*resultSize], data, sizeof(int)*pos);
        returnColumnSizes[*resultSize] = pos;
        (*resultSize)++;
        return;
    }

    data[pos] = nums[0];
    genSubset(nums+1, numsSize-1, data, pos+1, result, resultSize, returnColumnSizes);
    genSubset(nums+1, numsSize-1, data, pos, result, resultSize, returnColumnSizes);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int data[numsSize];
    long size = 1 << numsSize;
    int **result = malloc(sizeof(int *)*size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    *returnSize = 0;
    genSubset(nums, numsSize, data, 0, result, returnSize, *returnColumnSizes);
    return result;
}