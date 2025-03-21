/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n = gridSize;
    char *hashtable = calloc(1, n*n+1);
    int sum = 0;
    int foundRepeat = false;
    int repeated, missing;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += grid[i][j];
            if (!foundRepeat) {
                hashtable[grid[i][j]]++;
                if(hashtable[grid[i][j]] == 2){
                    foundRepeat = true;
                    repeated = grid[i][j];
                }
            }
        }
    }
    missing = repeated + ((1+n*n)*n*n/2 - sum);
    int *result = malloc(sizeof(int)*2);
    result[0] = repeated;
    result[1] = missing;
    *returnSize = 2;
    return result;
}