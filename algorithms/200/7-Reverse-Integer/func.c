int reverse(int x){
	char digit[10];
	int i, j;
	int sign = 1;
	long scale = 1;
	long y = x;
	long result = 0;

	/* get sign */
	if (y < 0) {
		sign = -1;
		y = - y;
	}

	for (i = 0; i < 10; i++) {
		digit[i] = y % 10;
		y = y / 10;
		if (y == 0) {
			i++;
			break;
		}
	}

	for (j = i-1; j >= 0; j--) {
		result += digit[j]*scale;
		scale *= 10;
	}

	result *= sign;
	if (result > INT_MAX || result < INT_MIN)
		result = 0;

	return (int)result;
}
