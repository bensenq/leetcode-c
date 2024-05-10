#define bool int
#define true 1
#define false 0
bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {
        int i, j, k;
        if (matrixRowSize == 1 || *matrixColSizes == 1)
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
                j = i; k = 0;
                while(j < *matrixColSizes - 1 && k < (matrixRowSize - 1)) {
                        if (matrix[k][j] != matrix[k+1][j+1]) {
                                return false;
                        }
                        j++;
                        k++;
                }
        }       

        return true;
}

int main()
{
	int t1[4] = {1,2,3,4};
	int t2[4] = {5,1,2,3};
	int t3[4] = {9,5,1,2};
	int *t[3] = {t1, t2, t3};
	int w = 4;
	int h = 3;
	isToeplitzMatrix(t, h, &w);
}
