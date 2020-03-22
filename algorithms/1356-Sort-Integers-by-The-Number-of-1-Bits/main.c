static inline int calc_bits(unsigned int n) {
	unsigned int c = 0;
	while (n > 0)
	{
		if((n & 1) == 1)
			++c;
		n >>= 1;
	}
	return c;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){
	char *nr_bits;
	int *sorted;
	int i, j, t;

	sorted = malloc(sizeof(int) * arrSize);
	memcpy(sorted, arr, sizeof(int) * arrSize);

	/* step 1: calculate nr bits */
	nr_bits = malloc(arrSize);
	for (i = 0; i < arrSize; i++) {
		nr_bits[i] = calc_bits(arr[i]);
	}

	/* step 2: sort by nr_bits (insert) */
	for (i = 0; i < arrSize; i++) {
		int t1 = nr_bits[i];
		int t2 = sorted[i];
		for (j = i-1; j >= 0; j--) {
			if (t1 < nr_bits[j]) {
				sorted[j+1] = sorted[j];
				nr_bits[j+1] = nr_bits[j];
			} else {
				break;
			}
		}
		nr_bits[j+1] = t1;
		sorted[j+1] = t2;
	}

	/* step 3 */
	i = 0;
	while ( i < arrSize ) {
		int start, stop;
		start = i;
		i++;
		while (i < arrSize) {
			if ( nr_bits[i] != nr_bits[start]) {
				break;
			}
			i++;
		}

		stop = i;
		
		/* sort internel */
		for (i = start; i < stop; i++) {
			int t = sorted[i];
			for (j = i-1; j >= start; j--) {
				if (t < sorted[j]) {
					sorted[j+1] = sorted[j];
				} else {
					break;
				}
			}
			sorted[j+1] = t;
		}
	}
	free(nr_bits);
	*returnSize = arrSize;
	return sorted;
}

int main(void)
{
	int arr[9] = {0,1,2,3,4,5,6,7,8};
	int size;
	sortByBits(arr, 9, &size);
	return 0;
}
