int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int count = 0;
    for (int k = numsSize - 1; k >= 2; k--) {
        int i = 0;
        int j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                count += j - i;
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
}
