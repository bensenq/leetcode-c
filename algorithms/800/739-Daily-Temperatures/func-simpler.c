/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int n = temperaturesSize;
    int *stack = malloc(sizeof(int) * n);
    int *result = calloc(sizeof(int), n);
    *returnSize = n;
    int top = -1;
    for(int i = 0; i < n; i++) {
        while(top != -1 && temperatures[i] > temperatures[stack[top]]) {
            result[stack[top]] = i - stack[top];
            top--;
        }
        top++;
        stack[top] = i;
    }
    free(stack);
    return result;    
}
