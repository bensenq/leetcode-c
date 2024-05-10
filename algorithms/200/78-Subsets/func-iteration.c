int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    long size = 1 << numsSize;
    int **result = malloc(sizeof(int *)*size);
    *returnColumnSizes = malloc(sizeof(int) * size);
    *returnSize = size;

    /* initial state */
    result[0] = malloc(0);
    (*returnColumnSizes)[0] = 0;
    result[1] = malloc(sizeof(int*)*1);
    result[1][0] = nums[0];
    (*returnColumnSizes)[1] = 1;

    /* iteration */
    int order = 1, j = 2;    
    while (order < numsSize) {
        for (int k = 0; k < j; k++) {
            int len = (*returnColumnSizes)[k]+1;
            (*returnColumnSizes)[j+k] = len;
            result[j+k] = malloc(len*sizeof(int));
            memcpy(result[j+k], result[k], (len-1)*sizeof(int));
            result[j+k][len-1] = nums[order];
        }
        j <<= 1;
        order++;
    }
    return result;
}

int main() {
    int nums[] = {1,2,3};
    int size;
    int *resturnSize;
    subsets(nums, 3, &size, &resturnSize);
    return 0;
}