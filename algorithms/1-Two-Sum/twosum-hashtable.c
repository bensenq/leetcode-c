// 2-d array for hashtable
// 0 for not present, otherwise for index+1

#define BUCKETS 10000
#define BUCKET_SIZE ((2000000000)/BUCKETS)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int ** hashtable = calloc(BUCKETS, sizeof(int *));
	int i = 0;
	int *result = malloc(sizeof(int)*2);
	while (i < numsSize) {
		int hash = (nums[i] + 1000000000) / BUCKET_SIZE;
		int offset = (nums[i] + 1000000000) % BUCKET_SIZE;
		if (hashtable[hash] == 0) {
			hashtable[hash] = calloc(BUCKET_SIZE, sizeof(int));
			hashtable[hash][offset] = i + 1;
		} else if (hashtable[hash][offset] == 0) {
			hashtable[hash][offset] = i + 1;
		} else if (nums[i] * 2 == target) { 
			result[0] = i;
			result[1] = hashtable[hash][offset] - 1;
			goto found;
		}
		i++;
	}

	i = 0;
	while (i < numsSize) {
		int x = target - nums[i];
		int hash = (x + 1000000000) / BUCKET_SIZE;
		int offset = (x + 1000000000) % BUCKET_SIZE;
		if (hashtable[hash] != 0 && hashtable[hash][offset] != 0 
				&& i+1 != hashtable[hash][offset]) {
			result[0] = i;
			result[1] = hashtable[hash][offset] - 1;
			goto found;
		}
		i++;
	}

found:    
	//TODO: free allocated memory

	*returnSize = 2;
	return result;
}
