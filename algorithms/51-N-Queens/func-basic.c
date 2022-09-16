#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solveNQueensIter(int n, int curRow, int* colStat, char **data, int *count, char ****result, int *resultSize) {
    if (curRow == n) {
        if (*count == *resultSize) {
            *resultSize *= 2;
            *result = realloc(*result, sizeof(char **) * (*resultSize));
        }

        (*result)[*count] = malloc(sizeof(char *) * n);
        for(int i = 0; i < n; i++) {
            (*result)[*count][i] = strdup(data[i]);
        }
        *count += 1;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (colStat[i] != 1) {
            /* check cross line */
            int conflict = 0;
            for (int j = curRow - 1, k = i - 1; j >= 0 && k >= 0; j--, k--) {
                if (data[j][k] == 'Q') {
                    conflict = 1;
                    break;
                }
            }
            if (conflict) continue;

            for (int j = curRow - 1, k = i + 1; j >= 0 && k < n; j--, k++) {
                if (data[j][k] == 'Q') {
                    conflict = 1;
                    break;
                }
            }
            if (conflict) continue;

            colStat[i] = 1;
            data[curRow][i] = 'Q';
            solveNQueensIter(n, curRow+1, colStat, data, count, result, resultSize);
            data[curRow][i] = '.';
            colStat[i] = 0;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    int count = 0;
    int colStat[n];
    int resultSize = n;
    char **data = malloc(sizeof(char *) * n);
    char ***result = malloc(sizeof(char **) * n);
    for (int i = 0; i < n; i++) {
        data[i] = malloc(n+1);
        memset(data[i], '.', n);
        data[i][n] = 0;
        colStat[i] = 0;
    }

    solveNQueensIter(n, 0, colStat, data, &count, &result, &resultSize);

    for (int i = 0; i < n; i++) {
        free(data[i]);
    }    
    free(data);
    result = realloc(result, sizeof(char**) * count);
    *returnSize = count;
    *returnColumnSizes = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return result;
}

int main() {
    int returnSize;
    int n = 5;
    int *returnColumnSizes;
    solveNQueens(n, &returnSize, &returnColumnSizes);
    return 0;
}