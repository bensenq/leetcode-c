void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *result = nums1;
    int i = 0, j = 0, k = 0;
    int *nums1Dup;
    if (nums1Size == 0 || n == 0)
        return;
    nums1Dup = malloc(sizeof(int) * m);
    memcpy(nums1Dup, nums1, sizeof(int) * m);
    while(j < m && k < n) {
        if (nums1Dup[j] < nums2[k]) {
            nums1[i++] = nums1Dup[j++];
        } else {
            nums1[i++] = nums2[k++];
        }
    }
    
    if (j < m) {
        memcpy(&nums1[i], &nums1Dup[j], (m - j) * sizeof(int));
    } else {
        memcpy(&nums1[i], &nums2[k], (n - k) * sizeof(int));
    }
    free(nums1Dup);
}