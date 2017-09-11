/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
        int i, j;
        int *ret = malloc(findNumsSize * sizeof(int));
        for (i = 0; i < findNumsSize; i++) {
                ret[i] = -1;
                for (j = 0; j < numsSize; j++) {
                        if (findNums[i] == nums[j]) {
                                break;
                        }
                }
                for (j++; j < numsSize; j++) {
                        if (nums[j] > findNums[i]) {
                                ret[i] = nums[j];
                                break;
                        }
                } 
        }
        *returnSize = findNumsSize;
        return ret;
}
