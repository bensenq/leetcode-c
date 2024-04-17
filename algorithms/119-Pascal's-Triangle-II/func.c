/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int *prev = malloc(sizeof(int) * (rowIndex + 1));
    int *next = malloc(sizeof(int) * (rowIndex + 1));
    int *tmp;
    prev[0] = 1;
    int i = 1;
    while (i <= rowIndex) {
        next[0] = 1;
        next[i] = 1;
        for (int j = 1; j < i; j++) {
            next[j] = prev[j-1] + prev[j];
        }
        tmp = prev;
        prev = next;
        next = tmp;
        i++;
    }
    free(next);
    return prev;    
}