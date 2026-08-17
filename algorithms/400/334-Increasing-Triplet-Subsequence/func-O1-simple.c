//https://leetcode.com/problems/increasing-triplet-subsequence/solutions/5871897/simple-solution-with-explanation-by-tech-ou1d/

bool increasingTriplet(int* nums, int numsSize) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] <= min1) {
            min1 = nums[i];  // Update first minimum
        } else if(nums[i] <= min2) {
            min2 = nums[i];  // Update second minimum
        } else {
            return true;  // Found a third number greater than both
        }
    }
    return false;  // No triplet found
}
