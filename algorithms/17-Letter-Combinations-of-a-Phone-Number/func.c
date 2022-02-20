char *mapping[8]= {
    "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};
int maplen[8] = {3, 3, 3, 3, 3, 4, 3, 4};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    int len = strlen(digits);
    char **result;
    char *buf;
    int size;
    int i, j, k, l;
    int set;
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    size = 1;
    i = 0;
    // calc total nums and alloc required memory
    while (i < len) {
        size = size * maplen[digits[i]-'2'];
        i++;
    }
    
    buf = malloc(size * (len+1));
    result = malloc(size * sizeof(char *));
    i = 0; 
    set = 1;
    while (i < len) {   //position level
        int index = digits[i]-'2';
        int choice = maplen[index];
        int repeat = size / set / choice;
        int sizeperset = repeat * choice;
        j = 0;
        while (j < set) {   //set level
            k = 0;
            while(k < choice) { //choice level
                l = 0;
                while (l < repeat) {
                    buf[(j*sizeperset+k*repeat+l)*(len+1)+i] = mapping[index][k];
                    l++;
                }
                k++;
            }
            j++;
        }
        set = set * choice;
        i++;
    }
    i = 0;
    while (i < size) {
        result[i] = &buf[i*(len+1)];
        result[i][len] = 0;
        i++;
    }
    *returnSize = size;
    return result;
}