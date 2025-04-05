#define max(a, b) ((a) > (b) ? (a) : (b))
long long maximumTripletValue(int *nums, int numsSize) {
    int leftMax[numsSize], rightMax[numsSize];
    leftMax[0] = 0;
    rightMax[numsSize - 1] = 0;
    for (int i = 1; i < numsSize; i++) {
        leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        rightMax[numsSize - 1 - i] = max(rightMax[numsSize - i], nums[numsSize - i]);
    }
    long long res = 0;
    for (int j = 1; j < numsSize - 1; j++) {
        long long temp = (long long)(leftMax[j] - nums[j]) * rightMax[j];
        res = max(res, temp);
    }
    return res;
}