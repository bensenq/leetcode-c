// The median minimizes the sum of absolute deviations


int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int minMoves2(int* nums, int numsSize) {
    int n = numsSize;
    qsort(nums, n, sizeof(int), cmp_int);
    int median = nums[n/2];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if (nums[i] > median) ans += nums[i] - median;
        else ans += median - nums[i];
    }
    return ans;
}
