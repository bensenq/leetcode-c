long C(int n, int k) {
    if (k > n/2) k = n - k;
    long result = 1;
    for (int i = 1; i <= k; i++) {
        result = result*(n-k+i)/i;
    }
    return result;
}

long computeSize(int n) {
    int sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += C(n, i);
    }
    return sum;
}

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
        genSubset(nums+1+i, numsSize-i-1, s-1, data, pos+1, result, resultSize, returnColumnSizes);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int data[numsSize];
    long size = computeSize(numsSize);
    int **result = malloc(sizeof(int *)*size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    *returnSize = 0;
    for (int i = 0; i <= numsSize; i++) {
        genSubset(nums, numsSize, i, data, 0, result, returnSize, *returnColumnSizes);
    }
    return result;
}