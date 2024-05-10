int arrayPairSum(int* nums, int numsSize) {
	int hash[20001] = {0};
	int i, j;
	int tmp;
	int sum;

	for(i = 0; i < numsSize; i += 1) {
		hash[nums[i] + 10000] += 1;
	}

	for(i = 0, j = 0, sum = 0; j < numsSize; i += 1) {
		if(hash[i] != 0) {
			j += hash[i];

			tmp = j & 0x1;
			sum += (i - 10000) * (((hash[i] - tmp) >> 1) + tmp);
		}
	}

	return sum;
}
