int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target){
    int i, j, k;
    int min = __INT_MAX__;
    int result;
    int sum, closest;

	qsort(nums, numsSize, sizeof(int), compare);

    for(i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1])
			continue;
        j = i + 1;
        k = numsSize - 1;
        
        while (j < k) {
            if (j > i+1 && nums[j] == nums[j-1]) {
				j++;
				continue;
			}

			if (k < numsSize-2 && nums[k] == nums[k+1]) {
				k--;
				continue;
			} 
            sum = nums[i] + nums[j] + nums[k];
            closest = sum - target;
            if (closest < 0) {
                j++;
                closest = -closest;
                if (closest < min) {
                    min = closest;
                    result = sum;
                }
                continue;
            } else if (closest > 0) {
                k--;
                if (closest < min) {
                    min = closest;
                    result = sum;
                }
                continue;
            } else {
                return target;
            }
        }
    }
    return result;
}