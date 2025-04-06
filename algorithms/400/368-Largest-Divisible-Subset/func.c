// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    // Sort the array using qsort
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Create DP arrays to track subset sizes and previous indices
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* prev = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        prev[i] = -1;
    }
    
    int max_len = 1;
    int max_idx = 0;
    
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
                
                if (dp[i] > max_len) {
                    max_len = dp[i];
                    max_idx = i;
                }
            }
        }
    }
    
    // Reconstruct the subset
    int* result = (int*)malloc(max_len * sizeof(int));
    int idx = max_len - 1;
    int curr = max_idx;
    
    while (curr != -1) {
        result[idx--] = nums[curr];
        curr = prev[curr];
    }
    
    *returnSize = max_len;
    free(dp);
    free(prev);
    return result;
}