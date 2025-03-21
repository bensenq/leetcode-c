/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** cellsInRange(char* s, int* returnSize) {
    int w = s[3]-s[0]+1, h = s[4]-s[1]+1;
    int size = w * h;
    *returnSize = size;
    char **result = malloc(sizeof(char*) * size);
    int k = 0;
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            result[k] = malloc(3);
            result[k][0] = s[0] + i; 
            result[k][1] = s[1] + j;
            result[k][2] = 0;
            k++;
        }
    }
    return result;
}