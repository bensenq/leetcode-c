/** 
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
	char *fizz = strdup("Fizz");
	char *buzz = strdup("Buzz");
	char *fizzbuzz = strdup("FizzBuzz");
	char **ret = malloc(sizeof(char *) * n);
	int i;
	for (i = 0; i < n; i++) {
		char *a = malloc(20);
		int number = i+1;
		if((number % 3  == 0) && (number % 5  == 0))
			strcpy(a, fizzbuzz);
		else if (number % 3 == 0)
			strcpy(a, fizz);
		else if (number % 5 == 0)
			strcpy(a, buzz);
		else
			sprintf(a, "%d", number);
		ret[i] = a;
	}
	*returnSize = n;
	return ret;
}
