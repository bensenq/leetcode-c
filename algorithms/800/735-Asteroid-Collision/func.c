/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int *result = malloc(sizeof(int) * asteroidsSize);
    int i = 0, j = 0;
    while(i < asteroidsSize) {
        if (asteroids[i] > 0 || j == 0 || result[j-1] < 0) {
            result[j++] = asteroids[i++];
        } else {
            if (result[j-1] > -asteroids[i]) i++; 
            else if (result[j-1] == -asteroids[i]) { j--; i++; }
            else j--;
        }
    }
    *returnSize = j;
    result = realloc(result, sizeof(int)*j);
    return  result;
}