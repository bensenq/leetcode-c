/* two-pointer */
//ref: https://leetcode.com/problems/max-number-of-k-sum-pairs/solutions/961643/c-two-pointer-o-1-extra-space/?envType=study-plan-v2&envId=leetcode-75
#include <math.h>
int compare (const void * a, const void * b){
    return ( *(int*)a - *(int*)b );
}

int maxOperations(int* nums, int numsSize, int k){
    int ans = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    int i = 0, j = numsSize - 1;
    while(i < j) {
        if (nums[i] + nums[j] == k) {
            ans++;
            i++;j--;
        } else if (nums[i] + nums[j] > k) j--;
        else i++;
    }
    return  ans;
}
