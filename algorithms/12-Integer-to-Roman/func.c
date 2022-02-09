char * intToRoman(int num){
	char *result = malloc(15);
	char *ret;
	int i = 0, j;
	int x = num;
	int m = x / 1000;
	int n = x % 1000;
	for (j = 0; j < m; j++)
		result[i++] = 'M'; 
	m = n / 100;
	n = n % 100;
	if (m == 9) {
		result[i++] = 'C';
		result[i++] = 'M';
	} else if (m == 4) {
		result[i++] = 'C';
		result[i++] = 'D';
	} else {
		if (m >= 5)
			result[i++] = 'D';
		for(j = 0; j < m % 5; j++)
			result[i++] = 'C';
	} 

	m = n / 10;
	n = n % 10;
	if (m == 9) {
		result[i++] = 'X';
		result[i++] = 'C';
	} else if (m == 4) {
		result[i++] = 'X';
		result[i++] = 'L';
	} else {
		if (m >= 5)
			result[i++] = 'L';
		for(j = 0; j < m % 5; j++)
			result[i++] = 'X';
	}

	if (n == 9) {
		result[i++] = 'I';
		result[i++] = 'X';
	} else if (n == 4) {
		result[i++] = 'I';
		result[i++] = 'V';
	} else {
		if (n >= 5)
			result[i++] = 'V';
		for(j = 0; j < n % 5; j++)
			result[i++] = 'I';
	}
	ret = malloc(i+1);
	ret[i] = 0;
	memcpy(ret, result, i);
	free(result);
	return ret;
}
