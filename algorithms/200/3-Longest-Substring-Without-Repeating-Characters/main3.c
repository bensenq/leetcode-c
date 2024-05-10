/* sliding window */
int lengthOfLongestSubstring(char* s) {
	int i, j, k;
	int len = strlen(s);
	int window = 0;
	int longest = 0;
	int a[127] = {0};
	i = 0;
	while(i < len) {
		if (len - i <= longest)
			break;
		/* scale window */
		j = i + window;
		while (j < len) {
			if (a[s[j]] == 0) {
				a[s[j]] = 1;
				j++;
				window++;
			} else 
				break;
		
		}
		if (window > longest)
			longest = window;

		a[s[i]] = 0;
		i++;
		window = window - 1;
	}

	return longest;
}
