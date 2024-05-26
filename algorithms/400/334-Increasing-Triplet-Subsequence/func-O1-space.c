/* find first smallest, then find second smallest, then find the third and bingo. */

//https://leetcode.com/problems/increasing-triplet-subsequence/?envType=study-plan-v2&envId=leetcode-75

bool increasingTriplet(int* nums, int numsSize) {
    int n = numsSize;
    int c1 = INT_MAX, c2 = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (nums[i] <= c1) {
            c1 = nums[i];
        } else if (nums[i] <= c2) {
            c2 = nums[i];
        } else { 
            return true;
        }
    }
    return false;
}
