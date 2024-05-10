//use a constant space bitmap to track state as m and n <= 200

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    unsigned long long mbit[4] = {0, 0, 0, 0};  //256 bit for row
    unsigned long long nbit[4] = {0, 0, 0, 0};  //256 bit for col
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                mbit[i/64] |= 1ULL << (i%64);
                nbit[j/64] |= 1ULL << (j%64);
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        if ((mbit[i/64] & (1ULL << (i%64))) !=0) {
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if ((nbit[i/64] & (1ULL << (i%64))) !=0) {
            for (int j = 0; j < m; j++)
                matrix[j][i] = 0;
        }
    }
}