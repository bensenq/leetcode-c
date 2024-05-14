/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes) {
    int m = imgSize;
    int n = imgColSize[0];
    int **result = malloc(sizeof(int *) * m);
    *returnColumnSizes = malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        result[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0, sum = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                if (k < 0 || k >= m) continue;
                for (int l = j - 1; l <= j + 1; l++) {
                    if (l < 0 || l >= n) continue;
                    sum += img[k][l];
                    count++;
                }
            }
            result[i][j] = sum/count;
        }
    }
    *returnSize = m;
    return result;
}