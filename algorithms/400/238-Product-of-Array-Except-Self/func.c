/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int) * numsSize);
    ans[0] = nums[0];
    for (int i = 1; i < numsSize - 1; i++) {
        ans[i] = ans[i-1] * nums[i];
    }

    int right = 1;
    for (int i = numsSize - 1; i >= 1; i--) {
        ans[i] = ans[i-1] * right;
        right = right * nums[i];
    }
    ans[0] = right;

    *returnSize = numsSize;
    return ans;
}
