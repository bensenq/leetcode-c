//dp solution

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s, int len) {
	int left = 0, right = len-1;
	while (left <= right) {
		if (s[left] != s[right])
			break;
		left++;right--;
	}
	return (left > right);
}

struct dp {
	char **array;
	int size;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** partition(char* s, int* returnSize, int** returnColumnSizes) {
	int len = strlen(s);
	struct dp dp[len+1];
	dp[0].size = 1;
    dp[0].array = malloc(sizeof(char *));
    dp[0].array[0] = malloc(0);
	int i = 1;
    char *palindrome[len][len+1];
	while (i <= len) {
        dp[i].size = 0;
        dp[i].array = malloc(sizeof(char*) * 0);
		for (int j = 0; j < i; j++) {
			if (isPalindrome(s+j, i-j)) {
                palindrome[j][i-j] = strndup(s+j, i-j);
                int x = dp[i].size, y = dp[j].size;
				dp[i].array = realloc(dp[i].array, sizeof(char*) * (x + y));
				for (int k = 0; k < y; k++) {
                    int m = 0, n = 0;
                    dp[i].array[x+k]  = malloc(i);
                    while(m != j) {
                        dp[i].array[x+k][n] = dp[j].array[k][n];
                        m += dp[j].array[k][n];
                        n++;
                    }
                    strncpy(dp[i].array[x+k], dp[j].array[k], n);
                    dp[i].array[x+k][n] = i-j; 
				}
				dp[i].size = x + y;
			}
		}
		i++;
	}

	//extract result from dp[len]
	*returnSize = dp[len].size;
	int *columnSizes = malloc(dp[len].size * sizeof(int));
	char ***result = malloc(dp[len].size * sizeof(char **));
    *returnColumnSizes = columnSizes;
	for (int i = 0; i < dp[len].size; i++) {
		int size = 0, j = 0;
		while (size != len) {
            int l = dp[len].array[i][j];
            size += l;
			j++;
		}
        result[i] = malloc(sizeof(char*)*j);
        columnSizes[i] = j;
        size = 0; j = 0;
        while(size != len) {
            int l = dp[len].array[i][j];
            result[i][j] = palindrome[size][l];
            size += l;
            j++;
        }		
	}
	
	//cleanup dp[0] ~ dp[len] memory
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j < dp[i].size; j++)free(dp[i].array[j]);
		free(dp[i].array);
	}

	return result;
}