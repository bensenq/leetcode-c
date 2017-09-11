#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
	int i;
	int order = 1;
	int *result = malloc(sizeof(int)*(num+1));

	/* initial case: num = 0 -> result = [0]; num = 1 -> result = [0, 1] */
	while (i < 2) {
		result[i] = i;
		i++;
		if (i > num)
			goto finish;
	}

	while (i <= num) {
		int j = 1;
		/* result[1<<n] = 1 */
		result[i] = 1;
		i++;

		/* 
		 * result[1<<n+x] = result[x] + 1 
		 * and result[x] has been calculated
		 */
		while (j < (1 << order)) {
			if (i > num)
				goto finish;
			else {
				result[i] = result[j] + 1;
				i++; j++;
			}
		}
		order++;
	}
	
finish:
	*returnSize = num + 1;
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
