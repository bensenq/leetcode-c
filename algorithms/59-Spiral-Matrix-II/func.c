//based on 54-Spiral-Matrix

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){

    /* alloc result matrix */
    int **matrix = malloc(sizeof(int*) * n);
    *returnColumnSizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n; 
    }
    *returnSize = n;

    int r = 0, c = 0;
    int column = n;
    int row = n;
    int s = 1;
    while ( 1 ) {
        if (column == 0) break; //LEFT if possible
        int i = 0;              
        while (i < column) {    //could be optimized by memcpy func.
            matrix[r][c+i] = s;    
            s++; i++;
        }
        row--;
        c = c+column-1;
        r++;

        if (row == 0) break;    //DOWN if possible
        i = 0;
        while (i < row) {
            matrix[r+i][c] = s;
            s++; i++;
        }
        column--;
        r = r+row-1;
        c--;

        if (column == 0) break; //RIGHT if possible
        i = 0;
        while (i < column) {    //could be optimized by memcpy func.
            matrix[r][c-i] = s;
            s++; i++;
        }    
        row--;
        c = c-column+1;
        r--;

        if (row == 0) break;    //UP if possibe
        i = 0;
        while (i < row) {
            matrix[r-i][c] = s;
            s++; i++;
        }
        column--;
        r = r-row+1;
        c++;
    }

    return matrix;
}