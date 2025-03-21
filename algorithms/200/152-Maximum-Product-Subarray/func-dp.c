/* DP */
//https://leetcode.com/problems/maximum-product-subarray/solutions/48230/possibly-simplest-solution-with-o-n-time-complexity/

#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)
#define swap(a,b) 
int maxProduct(int* nums, int numsSize) {
    // store the result that is the max we have found so far
    int i;
    int imax, imin, tmp; 
    int r = nums[0];

    // imax/imin stores the max/min product of
    // subarray that ends with the current number nums[i]
    for (i = 1, imax = r, imin = r; i < numsSize; i++) {
        // multiplied by a negative makes big number smaller, small number bigger
        // so we redefine the extremums by swapping them
        if (nums[i] < 0) {
            tmp = imax;
            imax = imin;
            imin = tmp;
        }

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        imax = max(nums[i], imax * (double)nums[i]);    // overcome the overflow case
        imin = min(nums[i], imin * (double)nums[i]);

        // the newly computed max value is a candidate for our global result
        r = max(r, imax);
    }
    return r;
}