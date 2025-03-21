int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int ans = 1;
    qsort(nums, numsSize, sizeof(int), compare);
    int i = 1;
    int max = 1;
    while(i < numsSize) {
        if(nums[i]-nums[i-1] == 1) max++;
        else if(nums[i]-nums[i-1] > 1) {
            if (max > ans) ans = max;
            max = 1;
        }
        i++;
    }
    if (max > ans) ans = max;
    return ans;
}