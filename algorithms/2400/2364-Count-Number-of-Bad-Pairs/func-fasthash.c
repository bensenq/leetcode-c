#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long countBadPairs(int* nums, int numsSize) {
    long long bad_pairs = 0;
    int max_num = nums[0], min_num = nums[0];
    for (int i = 1; i < numsSize; i++) {
        max_num = MAX(max_num, nums[i]-i);
        min_num = MIN(min_num, nums[i]-i);
    }
    int *hashmap = calloc(max_num-min_num+1, sizeof(int));
    int offset = min_num;

    for (int i = 0; i < numsSize; i++) {
        int key = nums[i] - i - offset;
        int val = hashmap[key];
        bad_pairs += i - val;
        hashmap[key]++;
    }
    free(hashmap);
    return bad_pairs;
}