double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	bool odd = (nums1Size + nums2Size) % 2;
	int halfLen = (nums1Size + nums2Size + 1) / 2;
	int i, j, c;
	/* left queue and right queue, picked for selected value */
	int left, picked;
	/* for two middle value in even totalLen */
	int mid1, mid2;


	for (i = 0, j = 0, c = 0; c <= halfLen; c++) {
		if (i < nums1Size && j < nums2Size) {
			if (nums1[i] <= nums2[j]) {
				left = 1;
			} else 
				left = 0;
		} else if (i == nums1Size) {
			left = 0;
		} else {
			left = 1;
		}

		if (left == 1) {
			picked = nums1[i];
			i++;
		} else {
			picked = nums2[j];
			j++;
		}

		if (c == halfLen - 1  && odd == 1) {
			break;
		}

		if (c == (halfLen - 1) && odd == 0) {
			mid1 = picked;
		}

		if (c == halfLen && odd == 0) {
			mid2 = picked;
		}
	}
	if (odd)
		return (double)picked;
	else 
		return ((double)(mid1+mid2))/2;
}
