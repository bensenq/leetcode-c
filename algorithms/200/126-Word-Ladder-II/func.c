#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int inList(char *word, char **list, int size) {
    for (int i = 0; i < size; i++) {
        if(strcmp(word, list[i]) == 0)
            return i;
    }
    return -1;  //not in list
}

bool oneDiff(char *first, char *second) {
    int count = 0, i = 0;
    while(first[i] != 0) {
        if (first[i] != second[i]) {
            count++;
            if (count > 1) break;
        }
        i++;
    }
    if (count == 1) return true;
    else return false;
}

/* list to track next step */
struct successor {
    short index;
    struct successor *next;
};

struct successor * insert(struct successor *head, short index) {
    struct successor *t = malloc(sizeof(struct successor));
    t->index = index;
    t->next = head;
    head = t;
    return head;
}

void freelist(struct successor *head) {
    struct successor *t;
    while(head != 0) {
        t = head;
        head = head->next;
        free(t);
    }
}
/* end list helper */

void traverse(char** wordList, struct successor **suc, struct successor *p, char **data, int lenth, int *returnSize, char ****ans) {
    if(p == 0) {
        *returnSize += 1;
        *ans = realloc(*ans, sizeof(char**) * (*returnSize));
        (*ans)[*returnSize-1] = malloc(sizeof(char *) * lenth);
        for (int i = 0; i < lenth; i++) {
            (*ans)[*returnSize-1][i] = strdup(data[i]);
        }
    }

    while(p != 0) {
        strcpy(data[lenth], wordList[p->index]);
        traverse(wordList, suc, suc[p->index], data, lenth+1, returnSize, ans);
        p = p->next;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** findLadders(char* beginWord, char* endWord, char** wordList, int wordListSize, int* returnSize, int** returnColumnSizes) {
    char*** ans = malloc(sizeof(char **) * 0);
    *returnSize = 0;
    int endIndex = inList(endWord, wordList, wordListSize);
    if (endIndex == -1) return 0;  
    int len = strlen(beginWord);
    int *distance = calloc(sizeof(int), wordListSize);  //0 means not covered
    struct successor **suc = calloc(sizeof(struct successor*), wordListSize);
    struct successor *beginsuc = 0;
    
    int newReach;
    int found = 0;
    int currentDepth = 1;
    distance[endIndex] = 1;
    while(true) {
        newReach = 0;
        for (int i = 0; i < wordListSize; i++) {
            if (distance[i] == currentDepth) {
                if (oneDiff(beginWord, wordList[i])) {
                    beginsuc = insert(beginsuc, i);
                    found = 1;
                }
                if (found == 0) {
                    for(int j = 0; j < wordListSize; j++) {
                        if((distance[j] == 0 || distance[j] == currentDepth+1) && oneDiff(wordList[i], wordList[j])) {
                            suc[j] = insert(suc[j], i);
                            distance[j] = currentDepth+1;
                            newReach++;
                        }
                    }
                }
            }
        }
        if(found)break;
        if(newReach == 0)break;
        currentDepth++;
    }

    if (found) {
        char **data = malloc(sizeof(char*) * (currentDepth+1));
        for (int i = 0; i < currentDepth+1; i++) {
            data[i] = malloc(len+1);
        }
        strcpy(data[0], beginWord);
        traverse(wordList, suc, beginsuc, data, 1, returnSize, &ans);
        *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
        for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = currentDepth+1;
        for (int i = 0; i < currentDepth+1; i++) free(data[i]);
        free(data);
    }
    free(distance);
    freelist(beginsuc);
    for (int i = 0; i < wordListSize; i++) freelist(suc[i]);
    free(suc);
    return ans;
}

int main() {
    char *wordlist[] = {"hot","dot","dog","lot","log","cog"};
    char *beginWord = "hit";
    char *endWord = "cog";
    int wordListSize = 6;
    int returnSize;
    int *returnColumnSizes;
    char ***ans = findLadders(beginWord, endWord, wordlist, wordListSize, &returnSize, &returnColumnSizes);    
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}