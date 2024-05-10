#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize;
    int n = matrixColSize[0];
    int size = m * n;
    int l = 0, r = size - 1, mid;
    int value;
    while (l <= r) {
        mid = (l + r) / 2;
        value = matrix[mid/n][mid%n];
        if (target == value)
            return true;
        else if (target > value) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return false;
}