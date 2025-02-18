/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    *returnSize = n + 1;
    int* perm = (int*)malloc((n + 1) * sizeof(int));

    int min = 0;  // Minimum available number
    int max = n;  // Maximum available number

    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            // For 'I', use the smallest available number
            perm[i] = min++;
        } else {
            // For 'D', use the largest available number
            perm[i] = max--;
        }
    }

    // The last number will be the remaining one (min == max)
    perm[n] = min;

    return perm;
}