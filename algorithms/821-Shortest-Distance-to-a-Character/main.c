/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* S, char C, int* returnSize) {
	int i, j;
	int len = strlen(S);
	int *result = malloc(len * sizeof(int));    
	int *index = malloc(len * sizeof(int));
	int indexcount = 0;
	for (i = 0; i < len; i++) {
		if (S[i] == C) {
			result[i] = 0;
			index[indexcount] = i;
			indexcount++;
		}
	}

	for (i = 0; i < index[0]; i++)
		result[i] = index[0] - i;

	for (i = index[indexcount-1] + 1; i < len; i++)
		result[i] = i - index[indexcount-1];

	i = 0;
	while ((i+1) < indexcount) {
		for (j = index[i]; j <= (index[i] + index[i+1])/2; j++)
			result[j] = j - index[i];
		for (; j < index[i+1]; j++)
			result[j] = index[i+1] - j;
		i++;
	}
	free(index);
	*returnSize = len;
	return result;
}

int main(void)
{
	char *S = "loveleetcode";
	char C = 'e';
	int ret;
	shortestToChar(S, C, &ret);
}
