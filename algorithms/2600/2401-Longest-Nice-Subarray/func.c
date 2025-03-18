/* sliding window */
int longestNiceSubarray(int* nums, int numsSize) {
    int max = 1;
    int count = 1;
    int left = 0, right = 1;
    while(right < numsSize) {
        int i = right - 1;
        while(i >= left && (nums[i] & nums[right]) == 0) i--;
        if (i < left) {
            count++;
        } else {
            if (count > max) max = count;
            left = i + 1;
            count = right - left + 1;
        }
        right++;
    }

    if (count > max) max = count;
    return max;
}