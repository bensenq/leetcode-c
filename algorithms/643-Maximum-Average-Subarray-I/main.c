double findMaxAverage(int* nums, int numsSize, int k) {
	int i;
	int sum = 0;
	int x = 0;
	int max = 0;
	int maxindex = 0;
	for (i = k; i < numsSize; i++) {
		x = x + (nums[i] - nums[i-k]);
		if(x > max) {
			maxindex = (i-k+1);
			max = x;
		}
	}

	for (i = maxindex; i < (maxindex+k); i++) {
		sum = sum + nums[i];
	}

	return ((double)sum)/k;
}
