#include <stdlib.h>
#include <string.h>
/*
 * candidates is already sorted.
 */
void combinationSumCore(int* candidates, int candidatesSize, int target, 
        int* returnSize, int* returnColumnSizes, int start, int len, int *cdd, int **result, int *resultMax) {
    if (target == 0) {
        result[*returnSize] = malloc(len * sizeof(int));
        returnColumnSizes[*returnSize] = len;
        memcpy(result[*returnSize], cdd, len*sizeof(int));
        *returnSize += 1;
        if (*returnSize == *resultMax) {
            *resultMax = (*resultMax) * 2;
            result = realloc(result, (*resultMax)*sizeof(int *));
        }
        return;
    }


    cdd[len] = 0;
    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) {
            return;
        }

        if (cdd[len] == candidates[i])  //duplication
            continue;

        cdd[len] = candidates[i];
        combinationSumCore(candidates, candidatesSize, target-cdd[len], 
            returnSize, returnColumnSizes, i+1, len+1, cdd, result, resultMax);
        cdd[len+1] = 0;
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
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int temp[100];
    int resultSizeMax = 150;
    int **result = malloc(resultSizeMax * sizeof(int *));
    *returnColumnSizes = malloc(resultSizeMax * sizeof(int));
    *returnSize = 0;
    qsort(candidates, candidatesSize, sizeof(int), compare); 
    combinationSumCore(candidates, candidatesSize, target, returnSize, *returnColumnSizes, 0, 0, temp, result, &resultSizeMax);
    return result;
}

int main() {
    int ** ret = 0;
    int retSize;
    int *retColumnSizes = 0;
//    int x[] = {6,8,12,5,9,3,4,11};
    int x[] = {4,1,1,4,4,4,4,2,3,5};
    int i;
//    ret = combinationSum(x, 8, 31, &retSize, &retColumnSizes);
    ret = combinationSum2(x, 10, 10, &retSize, &retColumnSizes);

    for (i = 0; i < retSize; i++) {
        free(ret[i]);
    }

    if (ret != 0) {
        free(ret);
        free(retColumnSizes);
    }
    return 0;
}