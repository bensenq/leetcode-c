/* with the method used in Subset func-iteration.c */

int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int data[numsSize];
    long size = 1 << numsSize;  //size is the max possible size
    int **result = malloc(sizeof(int *)*size);
    *returnColumnSizes = malloc(sizeof(int) * size);

    qsort(nums, numsSize, sizeof(int), compare);

    /* initial state */
    int i, j, k;
    int count = 0, prevCount;
    while(count < numsSize && nums[count] == nums[0]) count++;
    for (i = 0; i <= count; i++) {
        (*returnColumnSizes)[i] = i;
        result[i] = malloc(sizeof(int)*i);
        for (j = 0; j < i; j++) {
            result[i][j] = nums[0];
        }
    }

    /* iteration */
    prevCount = count+1;
    for (i = i - 1;i < numsSize; i += count) {
        count = 0;
        while((count+i) < numsSize && nums[count+i] == nums[i]) count++;
        for (j = 1; j <= count; j++) {
            for (k = 0; k < prevCount; k++) {
                int len = (*returnColumnSizes)[k] + j;
                (*returnColumnSizes)[j*prevCount+k] = len;
                result[j*prevCount+k] = malloc(len*sizeof(int));
                memcpy(result[j*prevCount+k], result[k], (len-j)*sizeof(int));
                int p = len-j;
                while(p < len) {
                    result[j*prevCount+k][p++] = nums[i];
                }
            }
        }
        prevCount = (count+1)*prevCount;
    }
    *returnSize = prevCount;
    return result;
}
int main() {
    int nums[] = {1,2,2};
    int size;
    int *resturnSize;
    subsetsWithDup(nums, 3, &size, &resturnSize);
    return 0;
}