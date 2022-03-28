void permutation(int* nums, int numsSize, int index, int **result, int *resultindex) {
    int i;
    if (index == numsSize) {
        int *array = malloc(sizeof(int) * numsSize);
        memcpy(array, nums, sizeof(int) * numsSize);
        result[*resultindex] = array;
        *resultindex += 1;
    } else {
        for (i = index; i < numsSize; i++) {
            int t = nums[index];
            nums[index] = nums[i];
            nums[i] = t;
            permutation(nums, numsSize, index+1, result, resultindex);
            t = nums[i];
            nums[i] = nums[index];
            nums[index] = t;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **result;
    int *columnSizes;
    int i, size = 1, resultindex = 0;
    for(i = numsSize; i > 1; i--) {
        size *= i;
    }
    result = malloc(sizeof(int *) * size);
    columnSizes = malloc(sizeof(int) * size);
    permutation(nums, numsSize, 0, result, &resultindex);
    for(i = 0; i < size; i++){
        columnSizes[i] = numsSize;
    }
    *returnSize = size;
    *returnColumnSizes = columnSizes;    
    return result;
}