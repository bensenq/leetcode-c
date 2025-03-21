/* Kadane's Algo */
//1. Calculate prefix product in nums, 
//2. Calculate suffix product in nums.
//3. Return the max.

#define max(a,b) (a > b ? a : b)
int maxProduct(int* nums, int numsSize) {
    long n = numsSize;
    double res = nums[0], l = 0, r = 0; //use double to pass overflow case
    for (int i = 0; i < n; i++) {
        l =  (l ? l : 1) * nums[i];
        r =  (r ? r : 1) * nums[n - 1 - i];
        res = max(res, max(l, r));
    }
    return (int)res;
}