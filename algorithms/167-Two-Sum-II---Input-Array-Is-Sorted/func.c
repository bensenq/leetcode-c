/* two-pointer solution */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	int left, right, sum;
	int *result = malloc(sizeof(int) * 2);
	left = 0;
	right = numbersSize-1;
	while (left < right) { 
		sum = numbers[left] + numbers[right];
		if (sum == target)
            break;
        else if(sum > target) {
			right--;
		} else {
			left++;
		}
	}
    result[0] = left + 1;
    result[1] = right + 1;
    *returnSize = 2;
	return result;
}