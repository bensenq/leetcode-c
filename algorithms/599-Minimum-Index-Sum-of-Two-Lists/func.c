#include <stdlib.h>
#include <string.h>

#define MIN(X,Y) ((X) < (Y) ?  (X) : (Y))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    char **result = malloc(sizeof(char *) * MIN(list1Size, list2Size));
    int minsum = 2000;
    *returnSize = 0;
    for (int i = 0; i < list1Size; i++) {
        if (i > minsum) break;
        for (int j = 0; j < list2Size; j++) {
            if (i+j > minsum) break;
            if (strcmp(list1[i], list2[j]) == 0) {
                if (i+j < minsum) {
                    for (int k = 0; k < *returnSize; k++) free(result[k]);
                    result[0] = strdup(list1[i]);
                    *returnSize = 1;
                    minsum = i + j;
                } else {
                    result[*returnSize] = strdup(list1[i]);
                    *returnSize += 1;
                }
            }
        }
    }
    return result;
}