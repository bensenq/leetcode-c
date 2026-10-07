/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int *stack = malloc(sizeof(int) * pricesSize);
    int *result = calloc(sizeof(int), pricesSize);
    memcpy(result, prices, sizeof(int) * pricesSize);
    *returnSize = pricesSize;
    int n = pricesSize;
    int top = -1;
    for(int i = 0; i < n; i++) {
        while(top != -1 && prices[i] <= prices[stack[top]]) {
            result[stack[top]] -= prices[i];
            top--;
        }
        top++;
        stack[top] = i;
    }
    free(stack);
    return result;
}
