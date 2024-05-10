int calPoints(char** ops, int opsSize) {
	int i, j;
	int total;
	int *score = malloc(opsSize*sizeof(int));	/* valid score */
	
	for (i = 0, j = 0; i < opsSize; i++) {
		int pop = 0;
		if (strcmp(ops[i], "+") == 0) {
			score[j] = score[j-1] + score[j-2];
		} else if (strcmp(ops[i], "D") == 0) {
			score[j] = 2 * score[j-1];
		} else if (strcmp(ops[i], "C") == 0) {
			pop = 1;
		} else {
			score[j] = atoi(ops[i]);
		}

		if (!pop) {
			total += score[j];
			j++;
		} else {
			total -= score[j-1];
			j--;
		}
	}

	free(score);
	return total;
}
