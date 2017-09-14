void reverseWord(char *s, int len)
{
	int i;
	char tmp;
	for (i = 0; i < len/2; i++) {
		tmp = s[i];
		s[i] = s[len-i-1];	
		s[len-i-1] = tmp;
	}
}

char* reverseWords(char* s) {
	char *delim = " ";
	char *result = malloc(strlen(s) + 1);    
	char *next; 
	char *last = result;
	strcpy(result, s);
	next = strtok(result, delim);
	if (next != 0) {
		reverseWord(next, strlen(next)); 
		while((next = strtok(0, delim)) != 0) {
			*(next-1) = ' ';
			reverseWord(next, strlen(next));
		}
	}
	return result;
}

int main() {
	reverseWords("Let's take LeetCode contest");
	return 0;
}
