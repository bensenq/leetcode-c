/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int size = 0;
    int *result = malloc(sizeof(int)*fmin(m,n));
    for (int i = 0; i < m; i++) {
        int rowmin = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < matrix[i][rowmin]) {
                rowmin = j;
            }
        }
        int colmax = i;
        for (int k = 0; k < m; k++) {
            if (matrix[k][rowmin] > matrix[i][rowmin]) {
                colmax = k;
                break;
            }
        }
        if (colmax == i)
            result[size++] = matrix[colmax][rowmin];
    }
    *returnSize = size;
    return result;
}