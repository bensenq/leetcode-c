#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct possibleSet {
    char **possible;
    int count;
};

struct parenthesisList {
    char **prthlist;
    int count;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** generateParenthesis(int n, int* returnSize){
    struct possibleSet *pSet = malloc(sizeof(struct possibleSet) * n);  //max(n) == 8
    struct parenthesisList *pList = malloc(sizeof(struct parenthesisList) * n);  //max(n) == 8
    int l;
    char * tmp;

    pSet[0].possible = malloc(sizeof(char *) * 1);
    tmp = malloc(2);    //possible 1 ()
    tmp[0] = 1; tmp[1] = 0;                        //end
    pSet[0].possible[0] = tmp;
    pSet[0].count = 1;
    pList[0].prthlist = malloc(sizeof(char *) * 1);
    pList[0].prthlist[0] = strdup("()");
    pList[0].count = 1;
    if (n == 1) {
        goto out;
    }

    pSet[1].possible = malloc(sizeof(char *) * 2);
    tmp = malloc(3);    //possible 11 ()()
    tmp[0] = 1; tmp[1] = 1; tmp[2] = 0; //end
    pSet[1].possible[0] = tmp;
    tmp = malloc(2);    //possible 2 (())
    tmp[0] = 2; tmp[1] = 0; //end
    pSet[1].possible[1] = tmp;
    pSet[1].count = 2;
    pList[1].prthlist = malloc(sizeof(char *) * 2);
    pList[1].prthlist[0] = strdup("()()");
    pList[1].prthlist[1] = strdup("(())");
    pList[1].count = 2;   
    
    if (n == 2) {
        goto out;
    }

    /* generate possible pattern */
    l = 3;
    while (l-1 < n) {
        int i, j, k;
        int size = l;
        int c = 0;
        pSet[l-1].possible = malloc(sizeof(char *) * size);
        for (i = 1; i < l; i++) {
            struct possibleSet *pSet_rest= &pSet[l-i-1];
            for (j = 0; j < pSet_rest->count; j++) {
                tmp = calloc(1, l+1);
                tmp[0] = i;
                k = 0;
                while (pSet_rest->possible[j][k] != 0) {
                    tmp[k+1] = pSet_rest->possible[j][k];
                    k++;
                }

                if (c == size) {
                    size *= 2;
                    pSet[l-1].possible = realloc(pSet[l-1].possible, sizeof(char *) * size);
                }
                pSet[l-1].possible[c] = tmp;
                c++;
            }
        }
        if (c == size) {
            size *= 2;
            pSet[l-1].possible = realloc(pSet[l-1].possible, sizeof(char *) * size);
        }
        tmp = calloc(1, l+1);
        tmp[0] = l;
        pSet[l-1].possible[c] = tmp;
        c++;
        pSet[l-1].count = c;
        l++;
    }

    /* generate parentheses list*/
    l = 3;
    while (l <= n) {
        int i, j, k, s, t, u, index;
        int size = l * l;
        int c = 0;
        struct possibleSet * set = &pSet[l-1];
        struct parenthesisList * list = &pList[l-1];
        list->prthlist = malloc(sizeof(char *) * size);
        for (i = 0; i < set->count; i++) {
            j = 0;
            index = 0;
            s = 1;
            if (c+s >= size) {
                size *= 2;
                list->prthlist = realloc(list->prthlist, sizeof(char *) * size);
            }
            list->prthlist[c] = calloc(1, 2*l+1);
            while (set->possible[i][j] != 0) {
                if (set->possible[i][j] == 1) {
                    for (k = c; k < c+s; k++) {
                        list->prthlist[k][index] = '(';
                        list->prthlist[k][index+1] = ')';
                    }
                    index += 2; //advance
                } else if (set->possible[i][j] == 2) {
                    for (k = c; k < c+s; k++) {
                        list->prthlist[k][index] = '(';
                        list->prthlist[k][index+1] = '(';
                        list->prthlist[k][index+2] = ')';
                        list->prthlist[k][index+3] = ')';
                    }
                    index += 4; //advance
                } else {
                    struct parenthesisList * innerList = &pList[set->possible[i][j]-2];
                    int innerLen = 2*(set->possible[i][j]-1);
                    if (c+s*innerList->count >= size) {
                        // size = c+s*innerList->count;
                        size *= 2;
                        list->prthlist = realloc(list->prthlist, sizeof(char *) * size);
                    }
                    for (t = 1; t < innerList->count; t++) {
                        for (u = 0; u < s; u++) {
                            list->prthlist[c+t*s+u] = calloc(1, 2*l+1);
                            memcpy(list->prthlist[c+t*s+u], list->prthlist[c+u], index);
                        }
                    }
                    for (k = c; k < c+s*innerList->count; k++) {
                        list->prthlist[k][index] = '(';
                    }
                    index++;
                    for (t = 0; t < innerList->count; t++) {
                        for (u = 0; u < s; u++) {
                            memcpy(&list->prthlist[c+t*s+u][index], innerList->prthlist[t], innerLen);
                        }
                    }
                    index += innerLen;           
                    for (k = c; k < c+s*innerList->count; k++) {
                        list->prthlist[k][index] = ')';
                    }
                    s *= innerList->count;
                    index++;
                }
                j++;
            }
            c += s;
        }
        list->count = c;
        l++;
    }

out:
//TODO: free memory
//     i = n - 1 - 1;  
//     while(i >= 0) {
//         free(possible[i]);
//         i--;
//     }
//     return possible[n-1];
    
    *returnSize = pList[n-1].count;
    return pList[n-1].prthlist;
}

int main(void) {
    int i = 8;
    int size;
    while(i <= 8) {
        char **result = generateParenthesis(i, &size);
        int k;
        printf("n = %d: ", i);
        for (k = 0; k < size; k++) {
            printf("%s", result[k]);
            printf(" ");
        }
        printf("\n");
        i++;
    }
    return 0;
}
