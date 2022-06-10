char mapping[9]= "adgjmptw{";

void letterGen(char *digits, char digitsLen, char *combine, int start, char **result, int *resultSize) {
    if (start == digitsLen) {
        combine[start] = 0;
        result[*resultSize] = strdup(combine);
        (*resultSize)++;
        return;
    }

    char index = digits[start]-'2';
    for (char i = mapping[index]; i < mapping[index+1]; i++) {
        combine[start] = i;
        letterGen(digits, digitsLen, combine, start+1, result, resultSize);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    char **result = malloc(4*4*4*4*4*sizeof(char *));
    char digitsLen = strlen(digits);
    char combine[digitsLen+1];
    *returnSize = 0;
    if (digitsLen != 0)
        letterGen(digits, digitsLen, combine, 0, result, returnSize);
    return result;
}