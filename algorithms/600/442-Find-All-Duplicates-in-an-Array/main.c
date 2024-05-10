/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// when find a number i, flip the number at position i-1 to negative. 
// if the number at position i-1 is already negative, i is the number that occurs twice.
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
	int i, j;
	int *dup = malloc(numsSize/2 * sizeof(int));
	for (i = 0, j = 0; i < numsSize; i++) {
		int x = nums[i] > 0 ? nums[i] : -nums[i];
		if(nums[x - 1] > 0) {
			nums[x - 1] = -nums[x - 1];
		} else {
			dup[j] = x;
			j++;
		}
	}
	*returnSize = j;
	return dup;
}
