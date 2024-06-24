/* sort and binary search */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b) {
    char *x = *(char**) a, *y = *(char**) b;
    return strcmp(x, y);
}

char *** suggestedProducts(char ** products, int productsSize, char * searchWord, int* returnSize, int** returnColumnSizes) {
    int i, j, lo, mid, hi, swSize, *colSizes;
    lo = 0;
    swSize = strlen(searchWord);
    char ***ans = (char ***) calloc(swSize, sizeof(char**));
    colSizes = (int*) calloc(swSize, sizeof(int));
    *returnSize = swSize;
    *returnColumnSizes = colSizes;
    qsort(products, productsSize, sizeof(char*), compare);
    for (i = 0; i < swSize; ++i) {
        hi = productsSize;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (strncmp(products[mid],searchWord, i+1) >= 0) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if (lo >= productsSize || 
        strncmp(products[lo],searchWord, i+1)) {
            return ans;
        }
        ans[i] = (char**) malloc(3 * sizeof(char*));
        for (j = 0; j < 3 && lo+j < productsSize; ++j) {
            if (strncmp(products[lo+j],searchWord, i+1)) {
                break;
            }
            ans[i][j] = products[lo+j];
        }
        ans[i] = realloc(ans[i], j * sizeof(char*));
        colSizes[i] = j;
    }
    return ans;
}