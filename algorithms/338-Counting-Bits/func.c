/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    int *ret = malloc(sizeof(int) * (n+1));
    int i = 1;
    int shift = 1;
    ret[0] = 0;
    while(i <= n) {
        if(i == shift) {
            ret[i] = 1;
            shift *= 2;
        } else {
            ret[i] = 1 + ret[i - shift/2];
        }
        i++;
    }
    *returnSize = n + 1;
    return ret;
}