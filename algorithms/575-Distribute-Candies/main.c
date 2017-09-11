int distributeCandies(int* candies, int candiesSize) {
	int i, index;
	int kinds = 0;
	char *kind = malloc(200001);
	memset(kind, 0, 200001);
	for (i = 0; i < candiesSize; i++) {
		index = candies[i] + 100000;
		if (kind[index] == 0) {
			kinds++;
			kind[index] = 1;
		}
	}
	free(kind);
	return kinds <= (candiesSize/2) ? kinds : (candiesSize/2);
}
