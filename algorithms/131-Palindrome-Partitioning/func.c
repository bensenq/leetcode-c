//dp solution

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s, int len) {
	int i = 0;
	int half = (len + 1) / 2;
	while (i < half) {
		if (s[i] != s[len - 1 - i])
			break;
		i++;
	}
	return (i == half);
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
// char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    // char ***result = malloc(0 * sizeof(char **));
    // int *columnSizes = malloc(0 * sizeof(int));
    // char **current = malloc(0 * sizeof(char *));
    // *returnSize = 0;
    // return result;

char *** partition(char* s, int* returnSize, int** returnColumnSizes) {
	int len = strlen(s);
	struct dp dp[len];
	dp[0].size = 1;
	dp[0].array = malloc(sizeof(char *) * 1);
	dp[0].array[0] = strndup(s, 1);
	int i = 1;
	while (i < len) {
		if (isPalindrome(s, i+1)) {
			dp[i].size = 1;
			dp[i].array = malloc(sizeof(char*) * 1);
			dp[i].array[0] = strndup(s, i+1);
		} else {
			dp[i].size = 0;
			dp[i].array = malloc(sizeof(char*) * 0);
		}

		for (int j = 1; j <= i; j++) {
			if (isPalindrome(s+j, i+1-j)) {
				dp[i].array = realloc(dp[i].array, sizeof(char*) * (dp[i].size + dp[j-1].size));
				for (int k = 0; k < dp[j-1].size; k++) {
					char *tmp2 = dp[j-1].array[k];
					int tmp2size = strlen(dp[j-1].array[k]);
					char *tmp = malloc(strlen(tmp2) + (i+1-j) + 2);	// org + space + new(i+1-j) + null
					strncpy(tmp, tmp2, tmp2size);
					tmp[tmp2size] = ' ';
					strncpy(tmp+tmp2size+1, s+j, i+1-j);
					tmp[tmp2size+1+i+1-j] = 0;
					dp[i].array[dp[i].size+k] = tmp; 
				}
				dp[i].size += dp[j-1].size;
			}
		}
		i++;
	}

	//extract result from dp[len-1]
	*returnSize = dp[len-1].size;
	int *columnSizes = malloc(dp[len-1].size * sizeof(int));
	char ***result = malloc(dp[len-1].size * sizeof(char **));
	*returnColumnSizes = columnSizes;
	for (int i = 0; i < dp[len-1].size; i++) {
		int size = 0;
		char *token;
		char *saveptr;
		int j = 0;
		result[i] = malloc(0);
		for (char * str = dp[len-1].array[i]; ; str = NULL) {
			token = strtok_r(str, " ", &saveptr);
			if (token == NULL) break;
			result[i] = realloc(result[i], sizeof(char *) * (j+1));
			result[i][j] = strdup(token);
			j++;
		}
		columnSizes[i] = j;
	}
	
	//cleanup dp[0] ~ dp[len-1] memory
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < dp[i].size; j++)free(dp[i].array[j]);
		free(dp[i].array);
	}

	return result;
}

int main() {
	int size;
	int *columnSize;
	partition("aab", &size, &columnSize);
	return 0;
}