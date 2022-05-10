long C(int n, int k) {
    if (k > n/2) k = n - k;
    long result = n;
    for (int i = 1; i < k; i++) {
        result *= (n-i);
    }
    for (int i = 0; i < k; i++) {
        result /= (k - i);
    }
    return result;
}

void combinationCore(int n, int k, int* data, int pos, int start, int** result, int *resultSize) {
    if (pos == k) {
        result[*resultSize] = malloc(sizeof(int)*k);
        memcpy(result[*resultSize], data, sizeof(int)*k);
        (*resultSize)++;
        return;
    }

    if ((n + 1 - start) < (k - pos))
        return;

    for (int i = start; i <= n; i++) {
        data[pos] = i;
        combinationCore(n, k, data, pos+1, i+1, result, resultSize);
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int data[k];
    long size = C(n,k);
    int **result = malloc(sizeof(int *)*size);
    *returnSize = 0;
    combinationCore(n, k, data, 0, 1, result, returnSize);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return result;
}