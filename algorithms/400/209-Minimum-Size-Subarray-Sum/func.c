// two-pointer
int minSubArrayLen(int target, int* nums, int numsSize) {
    int ans = numsSize + 1;
    int i = 0, j = 0;
    int value = 0;
    while(true) {
        if (value >= target) {
            if (j - i < ans) ans = j - i;
            value -= nums[i];
            i++;   
        } else {
            if (j == numsSize) break;
            else { 
                value += nums[j];
                j++;
            }
        }
    }
    return ans == numsSize + 1 ? 0 : ans;
}
