/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *result = malloc(sizeof(int) * digitsSize);
    int i = digitsSize - 1;
    int add = 1;
    while (i >= 0 && add == 1) {
        if (result[i] != 9) {
            result[i] = digits[i] + 1;
            add = 0;
        } else {
            result[i] = 0;
        }
        i--;
    }

    if (i == -1 && add == 1) {
        free(result);
        *returnSize = digitsSize + 1;
        result = calloc(sizeof(int), digitsSize + 1);
        result[0] = 1;    
    } else { 
        while (i >= 0) {
            result[i] = digits[i];
            i--;
        }
        *returnSize = digitsSize;
    }
    
    return result;
}