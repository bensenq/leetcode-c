int inString(char *s, int len, char c) {
	int i;
	for (i = 0; i < len; i++) {
		if (c == s[i]) {
			return 1;
		}
	}
	return 0;
}

int lengthOfLongestSubstring(char* s) {
	int i, j;
	int len = strlen(s);
	int longest = 0;
	for (i = 0; i < len; i++) {
		int l = 1;
		if ((len - i) <= longest)
			break;
		for (j = i+1; j < len; j++, l++) {
			if (inString(s+i, j-i, s[j]))
				break;
		}
		if (l > longest)
			longest = l;
	}

	return longest;
}
