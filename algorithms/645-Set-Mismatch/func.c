

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int *result = malloc(sizeof(int) * 2);
    int i, temp;
    *returnSize = 2;
    for (i = 0; i < numsSize; i++) {
        while (nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
            temp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            nums[i] = temp;
        }
    }
    
    for (i = 0; i < numsSize; i++) {
        if (nums[i] != i+1)
            break;
    }
    result[0] = nums[i];
    result[1] = i+1;
    return result;
}