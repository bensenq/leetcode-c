/*
 * ret index of queue head
 */
int findHead(int** people, int count) {
	int i, j;
	int ret;
	int small = 0x7fffffff;
	for (i = 0; i < count; i++) {
		if (people[i][1] == 0 && people[i][0] < small) {
			ret = i;
			small = people[i][0];
		}
	}
	return ret;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize) {
	int i, j, h;
	int **reconstructed = malloc(sizeof(int*) * peopleRowSize);
	for (i = 0; i < peopleRowSize; i++) {
		reconstructed[i] = malloc(2 * sizeof(int));
		reconstructed[i][0] = people[i][0];
		reconstructed[i][1] = people[i][1];
	}
	i = 0;
	while (i < peopleRowSize) {
		int *tmp;
		/* find head */
		h = findHead(reconstructed + i, peopleRowSize - i); 
		/* swap head to start of the current queue */
		tmp = reconstructed[i];
		reconstructed[i] = reconstructed[i+h];
		reconstructed[i+h] = tmp;
		/* update left queue for next turn*/
		for (j = i + 1; j < peopleRowSize; j++) {
			if (reconstructed[i][0] >= reconstructed[j][0]) {
				reconstructed[j][1]--;
			}
		}
		/* cat head to tail of reconstructed queue */
		for (j = 0; j < i; j++) {
			if (reconstructed[j][0] >= reconstructed[i][0]) {
				reconstructed[i][1]++;
			}
		}
		i++;
	}
	*returnSize = peopleRowSize;
	return reconstructed;
}
