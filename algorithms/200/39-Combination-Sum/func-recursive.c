/*
 * candidates is already sorted.
 */
int** combinationSumCore(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int i = 0;
    int maxCandidateIndex, maxCandidate;
    int remain = target;
    int **result = 0;
    *returnSize = 0;
    *returnColumnSizes = 0;
    
    // filter: min(candidates) is larget than target, stop
    if (candidates[0] > target) {
        return 0;
    }

    // condition: the result array size is no larger than 150.
    result = malloc(sizeof(int *) * 150);
    *returnColumnSizes = malloc(sizeof(int) * 150);
    
    // filter: find max candidates that is not larger than target, no need for rest
    while (i < candidatesSize) {
        if (candidates[i] > target)
            break;
        i++;
    }
    maxCandidateIndex = i-1;
    maxCandidate = candidates[i-1];
    
    i = 0;
    remain = target;
    while (remain > 0) {
        int j, k;
        int subRetSize;
        int *subRetColumnSizes;
        int **subRet;
        if (maxCandidateIndex > 0) {
            subRet = combinationSumCore(candidates, maxCandidateIndex, remain, 
                &subRetSize, &subRetColumnSizes);
            for (j = 0; j < subRetSize; j++) {
                int size = subRetColumnSizes[j] + i;
                int curIndex = *returnSize;
                subRet[j] = realloc(subRet[j], sizeof(int) * size);
                (*returnColumnSizes)[curIndex] = size;
                result[curIndex] = subRet[j];
                for (k = 0; k < i; k++)
                    result[curIndex][subRetColumnSizes[j]+k] = maxCandidate;
                *returnSize += 1;
            }
            if (subRet != 0) {
                free(subRet);
                free(subRetColumnSizes);
            }
        }
        remain = remain - maxCandidate;
        i++;
    }

    if (remain == 0) {
        int k;
        int *tmp = malloc(sizeof(int) * i);
        (*returnColumnSizes)[*returnSize] = i;
        result[*returnSize] = tmp;
        for (k = 0; k < i; k++)
            result[*returnSize][k] = maxCandidate;
        *returnSize += 1;
    }

    return result;
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
    qsort(candidates, candidatesSize, sizeof(int), compare); 
    return combinationSumCore(candidates, candidatesSize, target, returnSize, returnColumnSizes);
}

int main() {
    int ** ret = 0;
    int retSize;
    int *retColumnSizes = 0;
    int x[] = {6,8,12,5,9,3,4,11};
    int i;
    ret = combinationSum(x, 8, 31, &retSize, &retColumnSizes);

    for (i = 0; i < retSize; i++) {
        free(ret[i]);
    }

    if (ret != 0) {
        free(ret);
        free(retColumnSizes);
    }
    return 0;
}