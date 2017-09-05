#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
	int *result = malloc(sizeof(int)*(num+1));
	int i;
	for (i = 0; i <= num; i++) {
		int count = 0;
		int n = 0;
		while (!(i < (1<<n))) {
			if (i & (1<<n))
				count++;
			n++;
		}
		result[i] = count;
	}
	*returnSize = num+1;
	return result;
}

int main(int argc, char *argv[])
{
	int *size;
	int *result;
	int i;

	result = countBits(atoi(argv[1]), size);
	for (i = 0; i < *size; i++)
		printf("%d ", result[i]);
	printf("\n");
}
