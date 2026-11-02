//merge sort
//time complexity: O(m+n)
//space complexity: O(1)
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    bool odd = (nums1Size + nums2Size) % 2;
    int halfLen = (nums1Size + nums2Size + 1) / 2;
    int i, j, c;
    /* for two middle value in even totalLen */
    int mid1, mid2;
    int select;

    for (i = 0, j = 0, c = 0; c <= halfLen; c++) {
        if (i < nums1Size && j < nums2Size) {
            if (nums1[i] <= nums2[j]) {
                select = 1;
            } else {
                select = 2;
            }
        } else if (i == nums1Size) {
            select = 2;
        } else {
            select = 1;
        }
        if(select == 1) {
            if(c == halfLen - 1) mid1 = nums1[i];
            else if(!odd && c == halfLen) mid2 = nums1[i];
            i++;
        } else {
            if(c == halfLen - 1) mid1 = nums2[j];
            else if(!odd && c == halfLen) mid2 = nums2[j];
            j++;
        }
    }

    if (odd)
        return (double)mid1;
    else
        return ((double)(mid1+mid2))/2;
}
