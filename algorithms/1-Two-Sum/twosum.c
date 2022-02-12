/*algo: two-pointer */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int left, right, sum;
    int i, found1, found2;
	int *result = malloc(sizeof(int) * 2);
    int *dupNums = malloc(sizeof(int) * numsSize);
    memcpy(dupNums, nums, numsSize*sizeof(int));
	qsort(dupNums, numsSize, sizeof(int), compare);
	left = 0;
	right = numsSize-1;
	while (left < right) { 
		sum = dupNums[left] + dupNums[right];
		if(sum > target) {
			right--;
		} else if (sum < target) {
			left++;
		} else {
			break;
		}
	}
    i = 0;
    found1 = 0, found2 = 0;
    while (i < numsSize) {
        if (found1 && found2) break;
        if (!found1 && nums[i] == dupNums[left]) {
            result[0] = i;
            found1 = 1;
        } else if(!found2 && nums[i] == dupNums[right]) {
            result[1] = i;
            found2 = 1;
        }
        i++;
    }

    *returnSize = 2;
	return result;
}