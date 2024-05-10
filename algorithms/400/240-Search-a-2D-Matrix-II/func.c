#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize;
    int n = matrixColSize[0];
    int size = m * n;
    int l, r, mid;
    int value;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (target == matrix[i][j])
            return true;
        
        if (target < matrix[i][j])
            break;
        /* binary search current row */
        if (target <= matrix[i][n-1]) {
            l = j; r = n - 1;
            while (l <= r) {
                mid = (l + r) / 2;
                value = matrix[i][mid];
                if (target == value)
                    return true;
                else if (target > value) {
                    l = mid+1;
                } else {
                    n = r;
                    r = mid-1;
                }
            }
        }
        

        /* binary search current col */
        if (target <= matrix[m-1][j]) {
            l = i; r = m - 1;
            while (l <= r) {
                mid = (l + r) / 2;
                value = matrix[mid][j];
                if (target == value)
                    return true;
                else if (target > value) {
                    l = mid+1;
                } else {
                    m = r;
                    r = mid-1;
                }
            }
        }

        /* or advance */
        i++; j++;
    }
    return false;
}