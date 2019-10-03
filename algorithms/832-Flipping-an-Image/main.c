/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes){
        int i, j;
        int **ret = malloc(sizeof(int *) * ASize);
        *returnColumnSizes = malloc(sizeof(int) * ASize);

        for ( i = 0; i < ASize; i++ ) {
                ret[i] = malloc(AColSize[i] * sizeof(int));
                for ( j = 0; j < AColSize[i]; j++ ) {
                        ret[i][j] = A[i][AColSize[i] - 1 - j] > 0 ? 0 : 1;
                }
                (*returnColumnSizes)[i] = AColSize[i];
        }
        *returnSize = ASize;
        return ret;
}
