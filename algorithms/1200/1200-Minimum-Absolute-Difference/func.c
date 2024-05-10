int compare(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
    qsort(arr, arrSize, sizeof(int),  compare);
    int i;
    int minDistance = 0x7FFFFFFF;
    int size = 0;
    int **result = malloc(sizeof(int *) * (arrSize - 1));
    *returnColumnSizes = malloc(sizeof(int) * (arrSize - 1));

    for (i = 1; i < arrSize; i++) {
        if(arr[i] - arr[i-1] < minDistance)
            minDistance = arr[i] - arr[i-1];
    }

    for (i = 1; i < arrSize; i++) {
        if (arr[i] - arr[i-1] == minDistance) {
            result[size] = malloc(sizeof(int) * 2);
            result[size][0] = arr[i-1];
            result[size][1] = arr[i];
            (*returnColumnSizes)[size] = 2;
            size++;
        }
    }
    result = realloc(result, sizeof(int*) * size);
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * size);

    *returnSize = size;

    return result;
}