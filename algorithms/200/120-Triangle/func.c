//dp

#define min(x, y) (x < y ? x : y)

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int result;
    int *min_prev = malloc(sizeof(int) * triangleSize);
    int *min_next = malloc(sizeof(int) * triangleSize);
    int *tmp;
    min_prev[0] = triangle[0][0];
    int i = 1;
    while (i < triangleSize) {
        min_next[0] = min_prev[0] + triangle[i][0];
        min_next[i] = min_prev[i-1] + triangle[i][i]; 
        for (int j = 1; j < i; j++) {
            min_next[j] = min(min_prev[j-1], min_prev[j]) + triangle[i][j];
        }
        tmp = min_prev;
        min_prev = min_next;
        min_next = tmp;
        i++;
    }
    result = min_prev[0];
    for (i = 1; i < triangleSize; i++) {
        if (min_prev[i] < result)
            result = min_prev[i];
    }
    free(min_prev);
    free(min_next);
    return result;     
}