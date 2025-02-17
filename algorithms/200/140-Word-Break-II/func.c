#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 20
#define MAX_SENTENCES 10000

void backtrack(char *s, int start, char **wordDict, int wordDictSize, char **tempPath, int pathSize, char ***res, int *returnSize) {
    int n = strlen(s);
    if (start == n) {
        // Join the words in tempPath to form a sentence
        int totalLength = 0;
        for (int i = 0; i < pathSize; ++i) {
            totalLength += strlen(tempPath[i]) + 1; // +1 for space
        }
        totalLength--; // Remove the last space

        (*res)[*returnSize] = (char *)malloc(totalLength + 1);
        (*res)[*returnSize][0] = '\0';
        for (int i = 0; i < pathSize; ++i) {
            strcat((*res)[*returnSize], tempPath[i]);
            if (i < pathSize - 1) {
                strcat((*res)[*returnSize], " ");
            }
        }
        (*returnSize)++;
        return;
    }

    for (int end = start + 1; end <= n; ++end) {
        char subStr[end - start + 1];
        strncpy(subStr, s + start, end - start);
        subStr[end - start] = '\0';

        int isValidWord = 0;
        for (int i = 0; i < wordDictSize; ++i) {
            if (strcmp(wordDict[i], subStr) == 0) {
                isValidWord = 1;
                break;
            }
        }

        if (isValidWord) {
            tempPath[pathSize] = strdup(subStr);
            backtrack(s, end, wordDict, wordDictSize, tempPath, pathSize + 1, res, returnSize);
            free(tempPath[pathSize]); // Free the duplicated string
        }
    }
}

char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    char **res = (char **)malloc(MAX_SENTENCES * sizeof(char *));
    char *tempPath[MAX_WORDS];
    *returnSize = 0;

    backtrack(s, 0, wordDict, wordDictSize, tempPath, 0, &res, returnSize);

    return res;
}