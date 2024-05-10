/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(sizeof(int *) * numRows);
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    *returnSize = numRows;
    (*returnColumnSizes)[0] = 1;
    result[0] = malloc(sizeof(int) * 1);
    result[0][0] = 1;
    int i = 1;
    while (i < numRows) {
        result[i] = malloc(sizeof(int) * (i+1));
        (*returnColumnSizes)[i] = i + 1;
        result[i][0] = 1;
        result[i][i] = 1;
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i-1][j-1] + result[i-1][j];
        }
        i++;
    }
    return result;
}