/* with the method used in Subset func2.c */
void genSubset(int *nums, int numsSize, int* data, int pos, int** result, int *resultSize, int *returnColumnSizes) {
    if (numsSize == 0) {
        result[*resultSize] = malloc(sizeof(int)*pos);
        memcpy(result[*resultSize], data, sizeof(int)*pos);
        returnColumnSizes[*resultSize] = pos;
        (*resultSize)++;
        return;
    }

    int i = 1;
    data[pos] = nums[0];
    genSubset(nums+1, numsSize-1, data, pos+1, result, resultSize, returnColumnSizes);
    while (numsSize - i > 0 && nums[i] == nums[0]) {
        i++;
    }
    genSubset(nums+i, numsSize-i, data, pos, result, resultSize, returnColumnSizes);
}

int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int data[numsSize];
    long size = 1 << numsSize;
    int **result = malloc(sizeof(int *)*size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    genSubset(nums, numsSize, data, 0, result, returnSize, *returnColumnSizes);
    return result;
}