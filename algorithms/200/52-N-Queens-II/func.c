#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solveNQueensIter(int n, int curRow, int* colStat, char **data, int *count) {
    if (curRow == n) {
        if (n % 2 && data[0][n/2] == 'Q') { 
            *count += 1;  //no need to mirror the middle one
        } else {  
            *count += 2;
        }
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

            /* another cross line */
            for (int j = curRow - 1, k = i + 1; j >= 0 && k < n; j--, k++) {
                if (data[j][k] == 'Q') {
                    conflict = 1;
                    break;
                }
            }
            if (conflict) continue;

            colStat[i] = 1;
            data[curRow][i] = 'Q';
            solveNQueensIter(n, curRow+1, colStat, data, count);
            data[curRow][i] = '.';
            colStat[i] = 0;
        }
    }
}

int totalNQueens(int n){
    int count = 0;
    int colStat[n];
    char **data = malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        data[i] = malloc(n);
        memset(data[i], '.', n);
        colStat[i] = 0;
    }

    for (int i = 0; i < (n+1)/2; i++) { //check half and generate another half(mirrored)
        colStat[i] = 1;
        data[0][i] = 'Q';
        solveNQueensIter(n, 1, colStat, data, &count);
        data[0][i] = '.';
        colStat[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        free(data[i]);
    }    
    free(data);

    return count;
}

int main() {
    return totalNQueens(5);
}