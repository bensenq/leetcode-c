/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define max(a, b) (a > b ? a : b)

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    *returnColumnSizes = malloc(sizeof(int) * (n-2));
    int **result = malloc(sizeof(int *) * (n-2));
    /* Up to Down */
    for (int j = 0; j < n; j++) {
        int maxUp = max(grid[0][j], grid[1][j]);
        for (int i = 0; i < n - 2; i++) {
            int maxDown = max(grid[i+1][j], grid[i+2][j]);
            grid[i][j] = max(maxUp, maxDown);
            maxUp = maxDown;
        }
    }

    /* Left to Right */
    for (int i = 0; i < n - 2; i++) {
        result[i] = malloc(sizeof(int) * (n-2));
        (*returnColumnSizes)[i] = n - 2;
        int maxLeft = max(grid[i][0], grid[i][1]);
        for (int j = 0; j < n - 2; j++) {
            int maxRight = max(grid[i][j+1], grid[i][j+2]);
            result[i][j] = max(maxLeft, maxRight);
            maxLeft = maxRight;
        }    
    }

    *returnSize = n - 2;
    return result;
}