void combinationSum3Core(int k, int n, int* data, int pos, int start, int** result, int *resultSize) {
    if (pos == k && n == 0) {
        result[*resultSize] = malloc(sizeof(int)*k);
        memcpy(result[*resultSize], data, sizeof(int)*k);
        (*resultSize)++;
        return;
    }

    if (pos == k)
        return;

    for (int i = start; i <= 9; i++) {
        if (n < i)
            break;
        data[pos] = i;
        combinationSum3Core(k, n-i, data, pos+1, i+1, result, resultSize);
    }
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int data[k];
    int **result = malloc(sizeof(int *)*126);   /* max possible number is C4/9 = 126 */
    *returnSize = 0;
    combinationSum3Core(k, n, data, 0, 1, result, returnSize);
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return result;
}

int main() {
    int ret;
    int *retSize;
    combinationSum3(3, 7, &ret, &retSize);
    return 0;
}