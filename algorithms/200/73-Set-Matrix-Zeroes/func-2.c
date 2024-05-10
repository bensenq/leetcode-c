//ref: https://leetcode.com/problems/set-matrix-zeroes/discuss/26014/Any-shorter-O(1)-space-solution
//store states of each row in the first of that row, and store states of each column in the first of that column.

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int col0 = 1;   //init. to non-zero
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                if (j == 0) col0 = 0;
                else matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    
    // rows excpet row0
    for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < n; j++)
                matrix[i][j] = 0;
        }
    }

    // cols excpet col0
    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < m; i++)
                matrix[i][j] = 0;
        }
    }

    // row0
    if (matrix[0][0] == 0) {
        for (int j = 1; j < n; j++)
            matrix[0][j] = 0;
    }

    // col0
    if (col0 == 0) {
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;    
    }
}