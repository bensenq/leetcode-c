char* reverseVowels(char* s) {
	int *pos = malloc(strlen(s)*sizeof(int));
	char *vowelseq = malloc(strlen(s));
	int i = 0, j = 0, k;
	while (*(s+i) != NULL) {
		if (*(s+i) == 'a' ||
		    *(s+i) == 'e' ||
		    *(s+i) == 'i' ||
		    *(s+i) == 'o' ||
		    *(s+i) == 'u' ||
		    *(s+i) == 'A' ||
		    *(s+i) == 'E' ||
		    *(s+i) == 'I' ||
		    *(s+i) == 'O' ||
		    *(s+i) == 'U') {
			pos[j] = i;
			vowelseq[j] = *(s+i);
			j++;
		}
		i++;
	}

	for (k = 0; k < j; k++) {
		s[pos[k]] = vowelseq[j-k-1];
	}
	free(pos);
	free(vowelseq);

	return s;
}
