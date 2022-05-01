

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int r = matrixSize;
    int c = matrixColSize[0];
    int i, j;
    int *t = malloc(sizeof(int) * r * c);
    int **result = malloc(sizeof(int *) * c);
    int *columnSizes = malloc(sizeof(int) * c);
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            t[j*r+i] = matrix[i][j];
        }
    }
    
    for (i = 0; i < c; ++i) {
        result[i] = t + i*r;
        columnSizes[i] = r;
    }
    *returnSize = c;
    *returnColumnSizes = columnSizes;
    return result;
}