#include <stdlib.h>
#include <string.h>

// hash-table
typedef struct _hlist {
    int index;
    struct _hlist * next_h;
    struct _hlist * next_v;
} hlist;

int compare(const void *s1, const void *s2) {
    return (*(char *)s1) - (*(char *)s2);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char **strsTrans = malloc(sizeof(char *)*strsSize);
    for (int i = 0; i < strsSize; i++) {
        strsTrans[i] = strdup(strs[i]);
        qsort(strsTrans[i], strlen(strsTrans[i]), sizeof(char), compare);
    }

    *returnSize = 0;
    hlist **head = calloc(sizeof(hlist *), 101);
    for (int i = 0; i < strsSize; i++) {
        int hash = strlen(strs[i]); //hash by len
        if (head[hash] == 0) {
            head[hash] = calloc(sizeof(hlist), 1);
            head[hash]->index = i;
            *returnSize += 1;
        } else {
            hlist *t = head[hash];
            hlist *prev;
            while(t != 0) {
                if (strcmp(strsTrans[i], strsTrans[t->index]) == 0) { //found
                    hlist *tt = t;
                    while(tt->next_v != 0) {
                        tt = tt->next_v;
                    }
                    /* add to the group */
                    tt->next_v = calloc(sizeof(hlist), 1);
                    tt->next_v->index = i;
                    break;
                } else {
                    prev = t;
                    t = t->next_h;
                }
            }

            if (t == 0) {
                /* add to tail for a new group */
                prev->next_h = calloc(sizeof(hlist), 1);
                prev->next_h->index = i;
                *returnSize += 1;
            }
        }
    }

    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    char ***result = malloc(*returnSize * sizeof(char**));
    int count = 0;
    for (int i = 0; i < 101; i++) {
        if (head[i] != 0 ) {
            hlist *t = head[i];
            while (t != 0) {
                hlist *tt = t;
                int c = 0;
                while (tt != 0) {
                    tt = tt->next_v;
                    c++;
                }
                result[count] = malloc(sizeof(char *) * c);
                (*returnColumnSizes)[count] = c;
                tt = t;
                c = 0;
                while (tt != 0) {
                    result[count][c] = strdup(strs[tt->index]);
                    tt = tt->next_v;
                    c++;
                }
                count++;
                tt = t;
                t = t->next_h;
                while (tt != 0) {
                    hlist *ttt = tt;
                    tt = tt->next_v;
                    free(ttt);
                }    
            }

        }
    }

    //do clean up
    free(strsTrans);
    free(head);

    return result;
}

int main() {
    char *test[6] = {"eat","tea","tan","ate","nat","bat"};
    int returnSize;
    int *returnColumnSizes;
    groupAnagrams(test, 6, &returnSize, &returnColumnSizes);
}