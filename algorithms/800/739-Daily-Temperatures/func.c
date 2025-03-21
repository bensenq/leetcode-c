//Monotonic Decreasing Stack

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int n = temperaturesSize;
    int *t = temperatures;
    int stack[n][2], top = 0;
    int *answer = calloc(sizeof(int), n);
    for (int i = 0; i < n; i++) {
        while (top != 0 && t[i] > stack[top-1][0]) {
            int k = stack[top-1][1];
            answer[k] = i - k;
            top--;
        }
        stack[top][0] = t[i];
        stack[top][1] = i;
        top++;
    }
    *returnSize = n;
    return answer;
}