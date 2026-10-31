typedef struct {
    int **matrix;
    int **prefix_sum;
    int row;
    int col;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize, m = matrixColSize[0];
    NumMatrix *obj = malloc(sizeof(NumMatrix));
    int **prefix_sum = malloc(sizeof(int*) * (n + 1));
    for(int i = 0; i <= n; i++) prefix_sum[i] = malloc(sizeof(int) * (m + 1));
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= m; j++) {
            sum = sum + matrix[i-1][j-1];
            prefix_sum[i][j] = prefix_sum[i-1][j] + sum;
        }
    }
    obj->row = n;
    obj->col = m;
    obj->matrix = matrix;
    obj->prefix_sum = prefix_sum;
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    return obj->prefix_sum[row2+1][col2+1] - obj->prefix_sum[row1][col2+1] 
            - obj->prefix_sum[row2+1][col1] + obj->prefix_sum[row1][col1];
}

void numMatrixFree(NumMatrix* obj) {

    for(int i = 0; i <= obj->row; i++) free(obj->prefix_sum[i]);
    free(obj->prefix_sum);
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/
