#define INT_MIN -2147483648
int maxSubArray(int* nums, int numsSize){
    int i = 0;
    int sum = 0;
    int max = INT_MIN;
    while (i < numsSize) {
        sum += nums[i];
        if (sum > max) {
            max = sum;
        }
        if (sum <= 0) {
            sum = 0;
        }
        i++;
    }
    return max;
}