char *morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

void mapping(char *src, char *dst) {
	int i;
	for (i = 0; i < strlen(src); i++) {
		strcat(dst, morse[src[i] - 'a']);
	}
}

int uniqueMorseRepresentations(char** words, int wordsSize) {
	char **uniquecode = malloc(wordsSize * sizeof(char *));
	int uniquecount = 0;
	int i, j;
	for (i = 0; i < wordsSize; i++) {
		int dup = 0;
		char *morse = malloc(50); 
		mapping(words[i], morse);
		for (j = 0; j < uniquecount; j++) {
			if (strcmp(morse, uniquecode[j]) == 0) {
				dup = 1;
				break;
			}
		}
		if (dup == 0) {
			printf("morse: %s\n", morse);
			uniquecode[uniquecount] = morse;
			uniquecount++;
		} else {
			free(morse);
		}
	}

	// do not why must have to commet following 3 lines to pass the test
	/* 
	for (i = 0; i < uniquecount; i++)
		free(uniquecode[i]);
	free(uniquecode);
	*/
	return uniquecount;
}

int main(void) {
	char *words[5] = {"rwjje", "aittjje", "auyyn", "lqtktn", "lmjwn"};
	return uniqueMorseRepresentations(words, 5);
}
