//Editoral Approach 2: Greedy
/*
 * if we fix k, then the value of the triplet is maximized when nums[i]−nums[j] takes the 
 * maximum value. We can use imax to maintain the maximum value of nums[i], and dmax to
 * maintain the maximum value of nums[i]−nums[j]. During the enumeration of k, update dmax 
 * and imax.
 */

 #define max(a, b) ((a) > (b) ? (a) : (b))
 long long maximumTripletValue(int* nums, int numsSize) {
     long long res = 0, imax = 0, dmax = 0;
     for (int k = 0; k < numsSize; k++) {
         res = max(res, dmax * nums[k]);
         dmax = max(dmax, imax - nums[k]);
         imax = max(imax, nums[k]);
     }
     return res;
 }