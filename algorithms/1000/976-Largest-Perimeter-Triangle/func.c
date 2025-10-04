int compare_desc(const void *a, const void *b) {
return *(int *)b - *(int *)a;
}

int largestPerimeter(int* nums, int numsSize) {
    int max = 0;
    qsort(nums, numsSize, sizeof(int), compare_desc);
    for (int i = 0; i < numsSize; i++) {
        if(i + 1 < numsSize && nums[i] >= nums[i+1] * 2) continue;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] >= nums[j] * 2) break;
            for (int k = j+1; k < numsSize; k++) {
                if (nums[i] >= nums[j] + nums[k]) break;
                else {
                    max = nums[i] + nums[j] + nums[k];
                    goto out;
                }
            }
        }
    }
out:
    return max;
}
