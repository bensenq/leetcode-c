/*
 * candidates is already sorted.
 */
void combinationSumCore(int* candidates, int candidatesSize, int target, 
        int* returnSize, int* returnColumnSizes, int start, int len, int *cdd, int **result) {
    if (target == 0) {
        result[*returnSize] = malloc(len * sizeof(int));
        returnColumnSizes[*returnSize] = len;
        memcpy(result[*returnSize], cdd, len*sizeof(int));
        *returnSize += 1;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) {
            return;
        }
        cdd[len] = candidates[i];
        combinationSumCore(candidates, candidatesSize, target-cdd[len], 
            returnSize, returnColumnSizes, i, len+1, cdd, result);
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
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int temp[500];
    int **result = malloc(150 * sizeof(int *));
    *returnColumnSizes = malloc(150 * sizeof(int));
    *returnSize = 0;
    qsort(candidates, candidatesSize, sizeof(int), compare); 
    combinationSumCore(candidates, candidatesSize, target, returnSize, *returnColumnSizes, 0, 0, temp, result);
    return result;
}

int main() {
    int ** ret = 0;
    int retSize;
    int *retColumnSizes = 0;
//    int x[] = {6,8,12,5,9,3,4,11};
    int x[] = {2,3,6,7};
    int i;
//    ret = combinationSum(x, 8, 31, &retSize, &retColumnSizes);
    ret = combinationSum(x, 4, 7, &retSize, &retColumnSizes);

    for (i = 0; i < retSize; i++) {
        free(ret[i]);
    }

    if (ret != 0) {
        free(ret);
        free(retColumnSizes);
    }
    return 0;
}