int compare (const void * a, const void * b){
	return ( **(int**)a - **(int**)b );
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int ** result = malloc(sizeof(int *) * intervalsSize);
    int size = 0;
    qsort(intervals, intervalsSize, sizeof(int*), compare);
    int start = intervals[0][0], end = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][1] <= end) {
            continue;
        } else if (intervals[i][0] <= end && intervals[i][1] > end) {
            end = intervals[i][1];
        } else {
            result[size] = malloc(sizeof(int)*2);
            result[size][0] = start;
            result[size][1] = end;
            start = intervals[i][0];
            end = intervals[i][1];
            size++;
        }
    }

    result[size] = malloc(sizeof(int)*2);
    result[size][0] = start;
    result[size][1] = end;
    size++;

    result = realloc(result, sizeof(int*)*size);
    *returnSize = size;
    *returnColumnSizes = malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}