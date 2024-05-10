/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    	int *ret;
	int i, j;
	int *unique1, *unique2;
	int unique1Size = 0, unique2Size = 0;
        int max, min;
	
	unique1 = malloc(sizeof(int) * nums1Size);
	unique2 = malloc(sizeof(int) * nums2Size);

	/* unique nums1 */
	for (i = 0; i < nums1Size; i++) {
		int found = 0;
		for (j = 0; j < unique1Size; j++) {
			if (nums1[i] == unique1[j]) {
				found = 1;
				break;
			}
		}
		if (!found) {
			unique1[j] = nums1[i];
			unique1Size++;
		}
	}

	/* unique nums2 */
	for (i = 0; i < nums2Size; i++) {
		int found = 0;
		for (j = 0; j < unique2Size; j++) {
			if (nums2[i] == unique2[j]) {
				found = 1;
				break;
			}
		}
		if (!found) {
			unique2[j] = nums2[i];
			unique2Size++;
		}
	}


	if (unique1Size > unique2Size) {
		max = unique1Size;
		min = unique2Size;
	} else {
		max = unique2Size;
		min = unique1Size;
	}
	ret = malloc(sizeof(int) * max);
	*returnSize = 0;
	for (i = 0; i < unique1Size; i++) {
		for (j = 0; j < unique2Size; j++) {
			if (unique1[i] == unique2[j]) {
				ret[*returnSize] = unique1[i];
				*returnSize = *returnSize + 1;
			}
		}
	}

	return ret;
}
