/* simulation */
int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int count = 0, i, j, k;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            for (k = 0; k < gridSize; k++) {
                if (grid[i][k] != grid[k][j])
                    break;
            }
            if (k == gridSize) count++;
        }
    }
    return count;
}