// increment n - 1 element is repalced by decrement 1 element.
int minMoves(int* nums, int numsSize) {
    int min = 1e9;
    int ans = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] < min) min = nums[i];
    }

    for(int i = 0; i< numsSize; i++) {
        ans += nums[i] - min;
    }
    return ans;
}
