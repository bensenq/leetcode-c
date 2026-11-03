int minMoves(int* nums, int numsSize) {
    int max = 0;
    int ans = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > max) {
            ans += i * (nums[i] - max);
            max = nums[i];
        }
        else {
            ans += max - nums[i];
        }
    }
    return ans;    
}
