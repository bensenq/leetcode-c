bool checkValid(int** matrix, int matrixSize, int* matrixColSize){
    int n = *matrixColSize;
    int i, j;
    char hash_r[n][n+1];
    char hash_c[n][n+1];
    memset(hash_r, 0, n*(n+1)); //pad zero
    memset(hash_c, 0, n*(n+1)); //pad zero

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int index = matrix[i][j];
            if (hash_r[i][index] == 0
                && hash_c[j][index] == 0) {
                hash_r[i][index] = 1;
                hash_c[j][index] = 1;
            } else {
                return false;
            }
        }
    }
    return true;
}