// hashmap by mod with linear probe for conflict
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

int probe(int* hashtab, int hsize, int val) {
    int idx = val & (hsize - 1);
    while (hashtab[idx] != INT_MAX && hashtab[idx] != val)
        idx = (idx + 1) & (hsize - 1);
    return idx;
}
int longestConsecutive(int* nums, int numsSize) {
    int max_len = 0;
    int curr_len = 0;
    int i = 0;
    int idx = 0;
    int hsize = MAX(16, next_pow2(numsSize * 2));
    int* hashtab = malloc(hsize * sizeof *hashtab);
    for (i = 0; i < hsize; ++i)
        hashtab[i] = INT_MAX;

    for (i = 0; i < numsSize; ++i) {
        idx = probe(hashtab, hsize, nums[i]);
        hashtab[idx] = nums[i];
    }
    for (i = 0; i < hsize; ++i) {
        if (hashtab[i] == INT_MAX)
            continue;
        idx = probe(hashtab, hsize, hashtab[i] - 1);
        if (hashtab[idx] != INT_MAX)
            continue;
        curr_len = 1;
        do
            idx = probe(hashtab, hsize, hashtab[i] + curr_len++);
        while (hashtab[idx] != INT_MAX);
        max_len = MAX(max_len, curr_len - 1);
    }

    free(hashtab);
    return max_len;
}