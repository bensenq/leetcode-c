int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}


/* nums already sorted */
int** threeSum(int* nums, int numsSize, int* returnSize, int target){
	int i, j, k;
	int len = 0;
	int **result, **old;
	int found;
    int size;
 	if (numsSize < 3) {
	     *returnSize = 0;
	     return 0;
	}

    size = numsSize;
  	result = malloc(size * sizeof(int *));
    
	for (i = 0; i < numsSize - 2; i++) {
        if (nums[i]*3 > target)
            break;
		if (i > 0 && nums[i] == nums[i-1])
			continue;
		found = 0;
		j = i + 1;
		k = numsSize - 1;
		while (j < k) { /* two-pointer */
            if (nums[j] * 2 + nums[i] > target)
                break;
			if (found && j > i+1 && nums[j] == nums[j-1]) {
				j++;
				continue;   //check repeated
			} else if (found && k < numsSize-2 && nums[k] == nums[k+1]) {
				k--;
				continue;   //check repeated
			} else {
				found = 0;  //clear found flag
			}

			if (nums[i] + nums[j] + nums[k] > target) {
				k--;
				continue;
			} else if (nums[i] + nums[j] + nums[k] < target) {
				j++;
				continue;
			} else {
				int *quadruplet = malloc(sizeof(int)*4);
				quadruplet[1] = nums[i];
				quadruplet[2] = nums[j];
				quadruplet[3] = nums[k];
                if (len == size) {
                    old = result;
                    size = size * 2;
                    result = malloc(size * sizeof(int *));
                    memcpy(result, old, len * sizeof(int *));
                    free(old);
                }
				result[len++] = quadruplet;
				j++;
				k--;
				found = 1;
			}
		}
	}
	*returnSize = len;
	return result;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
	int i, j, k;
	int len = 0;
	int **result, **old;
	int *columnSizes;
	int max, min;
	int found;
    int size;
    int buffSize = numsSize;
 	if (numsSize < 4) {
	     *returnSize = 0;
	     *returnColumnSizes = 0;
	     return 0;
	}

    result = 0;
	qsort(nums, numsSize, sizeof(int), compare);
    result = malloc(sizeof(int *) * buffSize);
    for (i = 0; i < numsSize - 3; i++) {
        int size;
        int **threeSumArray;
        if (nums[i] * 4 > target)   //no need to contine
            break;
		if (i > 0 && nums[i] == nums[i-1])
			continue;
        threeSumArray = threeSum(&nums[i+1], numsSize-i-1, &size, target-nums[i]);
        if (len + size > buffSize) {
            result = realloc(result, sizeof(int *)*(len + size));
            buffSize = len + size;
        }
        j = 0;
        while(j < size) {
            threeSumArray[j][0] = nums[i];
            result[len] = threeSumArray[j];
            j++;
            len++;
        }

    }
    *returnSize = len;
	columnSizes = malloc(len * sizeof(int*));
	for(i = 0; i < len; i++)
		columnSizes[i] = 4;
	*returnColumnSizes = columnSizes;
    return result;
}

int main() {
    int test[] = {1,0,-1,0,-2,2};
    int size;
    int *returnSize;
    fourSum(test, 6, 0, &size, &returnSize);
    return 0;
}
