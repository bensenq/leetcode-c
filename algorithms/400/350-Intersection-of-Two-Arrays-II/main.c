/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int i, j, k;
	int size = 0;
	int *ret; 
	char *removed;
	int *small, *large;
	int small_size, large_size;
	if (nums1Size <= nums2Size) {
		small = nums1;
		small_size = nums1Size;
		large = nums2;
		large_size = nums2Size;
	} else {
		small = nums2;
		small_size = nums2Size;
		large = nums1;
		large_size = nums1Size;
	}

	ret = malloc(sizeof(int) * small_size);
	removed = malloc(sizeof(int) * large_size);
	memset(removed, 0, large_size);

	for (i = 0; i < small_size; i++) {
		for (j = 0; j < large_size; j++) {
			if (small[i] == large[j]) {
				if (removed[j] == 0) {
					ret[size] = small[i];
					size++;
					removed[j] = 1;
					break;
				}
			}
		}
	}
	free(removed);
	*returnSize = size;
	return ret;
}

