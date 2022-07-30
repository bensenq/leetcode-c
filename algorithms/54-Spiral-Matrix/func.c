/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){

    *returnSize = matrixSize * matrixColSize[0];
    int *result = malloc(sizeof(int) * (*returnSize));
    
    int r = 0, c = 0;
    int column = matrixColSize[0];
    int row = matrixSize;
    int s = 0;
    while ( 1 ) {
        if (column == 0) break; //LEFT if possible
        int i = 0;              
        while (i < column) {    //could be optimized by memcpy func.
            result[s] = matrix[r][c+i];    
            s++; i++;
        }
        row--;
        c = c+column-1;
        r++;

        if (row == 0) break;    //DOWN if possible
        i = 0;
        while (i < row) {
            result[s] = matrix[r+i][c];
            s++; i++;
        }
        column--;
        r = r+row-1;
        c--;

        if (column == 0) break; //RIGHT if possible
        i = 0;
        while (i < column) {    //could be optimized by memcpy func.
            result[s] = matrix[r][c-i];
            s++; i++;
        }    
        row--;
        c = c-column+1;
        r--;

        if (row == 0) break;    //UP if possibe
        i = 0;
        while (i < row) {
            result[s] = matrix[r-i][c];
            s++; i++;
        }
        column--;
        r = r-row+1;
        c++;
    }
    return result;
}