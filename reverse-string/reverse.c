char* reverseString(char* s) {
	int i;
	int len = strlen(s);
	char *r = malloc(len + 1);
	for (i = 0; i < len; i++)
		r[len-i-1] = s[i];
	r[len] = 0;
	return r;
}
