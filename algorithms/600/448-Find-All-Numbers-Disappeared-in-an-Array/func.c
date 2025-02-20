/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    bool *hashtable = calloc(sizeof(bool), numsSize+1);
    int count = 0; 
    for (int i = 0; i < numsSize; i++) {
        if (hashtable[nums[i]] == false) {
            hashtable[nums[i]] = true;
            count++;
        }
    }

    int *result = malloc(sizeof(int) * (numsSize - count));
    int index = 0;
    for (int i = 1; i <= numsSize; i++) {
        if (hashtable[i] == false) {
            result[index++] = i;
        }
    }
    free(hashtable);
    *returnSize = index;
    return result;
}