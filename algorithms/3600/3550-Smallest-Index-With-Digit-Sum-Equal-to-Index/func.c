int smallestIndex(int* nums, int numsSize) {
    int ans = -1;
    int n = numsSize;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        int x = nums[i];
        while(x > 0) {
            sum += x % 10;
            x /= 10;
            if (sum > i) break;
        }
        if (sum == i) {
            ans = i;
            break;
        }
    }
    return ans;
}
