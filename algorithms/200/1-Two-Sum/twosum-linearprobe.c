#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))

int next_pow2(int val) {
    val--;
    val |= val >> 1;
    val |= val >> 2;
    val |= val >> 4;
    val |= val >> 8;
    val |= val >> 16;
    return val + 1;
}

struct hashtable {
    int value;
    int index;
};

int probe(struct hashtable* hashtab, int hsize, int val) {
    int idx = val & (hsize - 1);
    while (hashtab[idx].value != INT_MAX && hashtab[idx].value != val)
        idx = (idx + 1) & (hsize - 1);
    return idx;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0;
    int *result = malloc(sizeof(int)*2);
    int hsize = MAX(16, next_pow2(numsSize * 2));
    int idx;
    struct hashtable* hashtab = malloc(hsize * sizeof *hashtab);
    for (i = 0; i < hsize; ++i)
        hashtab[i].value = INT_MAX;
    for (i = 0; i < numsSize; ++i) {
        idx = probe(hashtab, hsize, nums[i]);
        if (hashtab[idx].value == INT_MAX) {
            hashtab[idx].value = nums[i];
            hashtab[idx].index = i;
            idx = probe(hashtab, hsize, target-nums[i]);
            if (hashtab[idx].value != INT_MAX && hashtab[idx].index != i) {
                result[0] = hashtab[idx].index;
                result[1] = i;
                goto found;
            }
        } else if(nums[i] * 2 == target) {
                result[0] = hashtab[idx].index;
                result[1] = i;
                goto found;
        } 
    }
    
found:    
    free(hashtab);
    *returnSize = 2;
    return result;
}