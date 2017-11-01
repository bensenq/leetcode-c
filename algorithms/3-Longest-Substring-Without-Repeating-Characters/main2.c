int lengthOfLongestSubstring(char* s) {
	int i, j;
	int len = strlen(s);
	int *leftSameOffset = malloc(sizeof(int) * len);
	int longest = 0;
	for (i = 0; i < len; i++) {
		leftSameOffset[i] = 0; /* no same in left */
		for (j = i - 1; j >= 0; j--) {
			if (s[j] == s[i]) {
				leftSameOffset[i] = i - j;
				break;
			}	
		}
	}

	for (i = 0; i < len; i++) {
		int l = 1;
		if ((len - i) <= longest)
			break;
		for (j = i+1; j < len; j++, l++) {
			if(leftSameOffset[j] > 0 && (j - leftSameOffset[j]) >= i)
				break;
		}
		if (l > longest)
			longest = l;
	}

	free(leftSameOffset);

	return longest;
}
