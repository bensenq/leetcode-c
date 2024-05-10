/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize){
    int *result;
    int i, j;
    *returnSize = 1 << n;
    result = malloc((1 << n) * sizeof(int));
    result[0] = 0;
    result[1] = 1;
    i = 1; j = 2;
    while (i < n) {
        int k = 0;
        while (k < j) {
            result[j + k] = result[j - k - 1] | (1 << i);
            k++;
        }
        j *= 2;
        i++;
    }
    return result;
}