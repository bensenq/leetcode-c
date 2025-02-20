// Editorial: Approach 4: Cantor's Diagonal Argument

// construct a string different from every string in nums

char* findDifferentBinaryString(char** nums, int numsSize) {
    int n = numsSize; 
    char* result = (char*)malloc((n + 1) * sizeof(char)); 
    for (int i = 0; i < n; i++) {
        result[i] = nums[i][i] == '0' ? '1' : '0'; 
    }
    result[n] = '\0';

    return result;
}