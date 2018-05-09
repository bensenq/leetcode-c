#define true 1
#define false 0
bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {
        int i, j, k;
        if (matrixRowSize == 0 || *matrixColSizes == 0)
                return true;

        for (i = matrixRowSize - 2; i > 0; i--) {
                j = i; k = 0;
                while(j < (matrixRowSize - 1) && k < (*matrixColSizes - 1)) {
                        if (matrix[j][k] != matrix[j+1][k+1]) {
                                return false;
                        }       
                        j++;
                        k++;
                }       
        }       

        for (i = 0 ; i < *matrixColSizes - 1; i++) {
                j = i; k = *matrixColSizes - 1;
                while(j > 0 && k > 0) {
                        if (matrix[j][k] != matrix[j-1][k-1]) {
                                return false;
                        }
                        j++;
                        k++;
                }
        }       

        return true;
}
