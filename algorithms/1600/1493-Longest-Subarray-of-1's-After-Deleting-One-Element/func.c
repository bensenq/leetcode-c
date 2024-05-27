/* sliding window like 1004 */
int longestSubarray(int* nums, int numsSize) {
    int i = 0, max = 0, len = 0, start = 0, deleted = 0;
    while(i < numsSize) {
        if (nums[i] == 1) len++;
        else {  /* nums[i] == 0 */
            if(deleted == 0) { /* delete */
                deleted = 1;
            } else {    /* could not advance */
                if (len > max) max = len;
                while(deleted == 1) {
                    if(nums[start] == 0) {
                        deleted = 0;    /* undelete */
                    } else {
                        len--;
                    }
                    start++;
                }
                deleted = 1;
            }
        }
        i++;
    }
    if (deleted == 0) len--;
    if (len > max) max = len;
    return max;
}