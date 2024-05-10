/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
	int *columnsize;
	int *matrix;
	int **ret;
	int i,j;
	matrix = malloc(numsRowSize * numsColSize * sizeof(int));
	for (i = 0; i < numsRowSize; i++) {
		for (j = 0; j < numsColSize; j++)
			matrix[i*numsColSize+j] = nums[i][j];
	}
	if ((numsRowSize*numsColSize > (r-1)*c) && numsRowSize*numsColSize <= r*c) {
		ret = malloc(r * sizeof(int *));
		columnsize = malloc(sizeof(int) * r);
		*returnSize = r;
		for (i = 0; i < (r-1); i++) {
			columnsize[i] = c;
			ret[i] = matrix + i*c;
		}
		columnsize[i] = (numsRowSize*numsColSize) % r ? (numsRowSize*numsColSize) % r : c;
		ret[i] = matrix + i*c;
		*columnSizes = columnsize;
	} else {
		ret = malloc(numsRowSize * sizeof(int *));
		columnsize = malloc(sizeof(int) * numsRowSize);
		*returnSize = numsRowSize;
		for (i = 0; i < numsRowSize; i++) {
			columnsize[i] = numsColSize;
			ret[i] = matrix + i*numsColSize;
		}
		*columnSizes = columnsize;
	}
	return ret;
}
