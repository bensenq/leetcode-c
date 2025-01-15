//ref: https://leetcode.com/problems/longest-consecutive-sequence/solutions/41055/my-really-simple-java-o-n-solution-accepted/

/* hushmap using uthash */
struct map {
    int id;                    /* key */
    int lenth;
    UT_hash_handle hh;         /* makes this structure hashable */
};

int longestConsecutive(int* nums, int numsSize) {
    int max = 0;
    struct map *numsmap = NULL;
    struct map *s, *t;
    int key;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(numsmap, &nums[i], s);  /* id already in the hash? */
        if (s == NULL) {
            int left = 0, right = 0, sum;
            key = nums[i]-1;
            HASH_FIND_INT(numsmap, &key, s);
            if (s != NULL) {
                left = s->lenth;
            }

            key = nums[i]+1;
            HASH_FIND_INT(numsmap, &key, s);
            if (s != NULL) {
                right = s->lenth;
            }
            
            // sum: length of the sequence n is in
            sum = left + right + 1;
            s = (struct map *)malloc(sizeof *s);
            s->id = nums[i];
            s->lenth = sum;
            HASH_ADD_INT(numsmap, id, s);  /* id: name of key field */

            // keep track of the max length 
            if (sum > max) max = sum;

            // extend the length to the boundary(s) of the sequence
            if (left != 0) {
                key = nums[i]-left;
                HASH_FIND_INT(numsmap, &key, s);
                s->lenth = sum;
            }

            if (right != 0) {
                key = nums[i]+right;
                HASH_FIND_INT(numsmap, &key, s);
                s->lenth = sum;
            }
        }
    }

    HASH_ITER(hh, numsmap, s, t) {
        HASH_DEL(numsmap, s);
        free(s);
    }
    return max;
}

