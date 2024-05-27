/* sliding window: keep max flipped number not over k */
int longestOnes(int* nums, int numsSize, int k) {
    int i = 0, max = 0, len = 0, start = 0;
    while(i < numsSize) {
        if (nums[i] == 1) len++;
        else {  /* nums[i] == 0 */
            if(k > 0) { /* flip */
                len++; k--;
            } else {    /* could not flip more */
                if (len > max) max = len;
                while(k == 0) {
                    if(nums[start] == 0) {
                        k++;    /* unflip one so we can advance */
                    }
                    start++;len--;
                }
                len++; k--;
            }
        }
        i++;
    }
    if (len > max) max = len;
    return max;
}