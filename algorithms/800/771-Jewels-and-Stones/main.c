/*
 * String is not the perfect structrure for this problem, 
 * as it is not easy to remove element.
 */
int numJewelsInStones(char* J, char* S) {
	int i, k;
	int lenJ = strlen(J);
	int lenS = strlen(S);
	int count = 0;
	for (i = 0; i < lenJ; i++) {
		char c = J[i];
		for (k = 0; k < lenS; k++) {
			if (c == S[k])
				count++;
		}
	}	
	return count;
}
