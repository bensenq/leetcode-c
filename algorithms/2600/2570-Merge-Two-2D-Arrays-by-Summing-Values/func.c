 int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSizes, int** nums2, int nums2Size, int* nums2ColSizes, int* returnSize, int** returnColumnSizes) {
    int p1 = 0, p2 = 0;
    int count = 0;
    int** result = (int**)malloc((nums1Size + nums2Size) * sizeof(int*));

    while (p1 < nums1Size && p2 < nums2Size) {
        if (nums1[p1][0] == nums2[p2][0]) {
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = nums1[p1][0];
            result[count][1] = nums1[p1][1] + nums2[p2][1];
            p1++;
            p2++;
        } else if (nums1[p1][0] < nums2[p2][0]) {
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = nums1[p1][0];
            result[count][1] = nums1[p1][1];
            p1++;
        } else {
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = nums2[p2][0];
            result[count][1] = nums2[p2][1];
            p2++;
        }
        count++;
    }

    while (p1 < nums1Size) {
        result[count] = (int*)malloc(2 * sizeof(int));
        result[count][0] = nums1[p1][0];
        result[count][1] = nums1[p1][1];
        p1++;
        count++;
    }

    while (p2 < nums2Size) {
        result[count] = (int*)malloc(2 * sizeof(int));
        result[count][0] = nums2[p2][0];
        result[count][1] = nums2[p2][1];
        p2++;
        count++;
    }

    *returnSize = count;
    *returnColumnSizes = (int*)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}