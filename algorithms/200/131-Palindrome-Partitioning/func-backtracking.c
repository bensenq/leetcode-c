//backtracking

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s, int len) {
    if (len == 1) return true;
	int left = 0, right = len-1;
	while (left <= right) {
		if (s[left] != s[right])
			break;
		left++;right--;
	}
	return (left > right);
}

void searchPalindrome(char *s, int len, char ***palindrome) {
    for (int i = 0; i < len; i++) {
        for (int j = 1; i+j <= len; j++) {
            if (j == 1 || isPalindrome(s+i, j)) {
                palindrome[i][j] = strndup(s+i, j);
            } else {
                palindrome[i][j] = 0;
            }
        }
    }
}

void partitionCore(char *s, int *lens, int index, int len, int offset, 
int *size, int *capicity, int **returnColumnSizes, char ****result, char ***palindrome) {
    if (offset == len) {
        *size += 1;
        if (*size > *capicity) {
            *capicity *= 2;
            *result = realloc(*result, sizeof(char **)*(*capicity));
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*(*capicity));
        }
        (*returnColumnSizes)[*size-1] = index;
        (*result)[*size-1] = malloc(sizeof(char *)*index);
        int i = 0, k = 0;
        while(i < index) {
            (*result)[*size-1][i] = palindrome[k][lens[i]];
            k += lens[i];
            i++;
        }
        return;
    }

    for (int i = 1; i <= len-offset; i++) {
        if (palindrome[offset][i] != 0) {
            lens[index] = i;
            partitionCore(s, lens, index+1, len, offset+i, size, capicity, returnColumnSizes, result, palindrome);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** partition(char* s, int* returnSize, int** returnColumnSizes) {
	int len = strlen(s);
	int size = 0;
    int capicity = 16;
    int lens[16];
	int *columnSizes = malloc(capicity * sizeof(int));
	char ***result = malloc(capicity * sizeof(char **));
    char *** palindrome= malloc(len * sizeof(char **));
    for (int i = 0; i < len; i++) {
        palindrome[i] = malloc((len+1) * sizeof(char*));
    }
    searchPalindrome(s, len, palindrome);
    *returnColumnSizes = columnSizes;
    for (int i = 1; i <= len; i++) {
        if (palindrome[0][i] != 0) {
            lens[0] = i;
            partitionCore(s, lens, 1, len, i, &size, &capicity, returnColumnSizes, &result, palindrome);
        }
    }
    result = realloc(result, sizeof(char **)*size);
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*size);
    *returnSize = size;
	return result;
}
