/* with the method used in Subset func.c */
void genSubset(int *nums, int numsSize, int s, int* data, int pos, int** result, int *resultSize, int *returnColumnSizes) {
    if (s == 0) {
        result[*resultSize] = malloc(sizeof(int)*pos);
        memcpy(result[*resultSize], data, sizeof(int)*pos);
        returnColumnSizes[*resultSize] = pos;
        (*resultSize)++;
        return;
    }

    if (numsSize < (s - pos))
        return;

    for (int i = 0; i < numsSize; i++) {
        data[pos] = nums[i];
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        genSubset(nums+1+i, numsSize-i-1, s-1, data, pos+1, result, resultSize, returnColumnSizes);
    }
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
    for (int i = 0; i <= numsSize; i++) {
        genSubset(nums, numsSize, i, data, 0, result, returnSize, *returnColumnSizes);
    }
    return result;
}