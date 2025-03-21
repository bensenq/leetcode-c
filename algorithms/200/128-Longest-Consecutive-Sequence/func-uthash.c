/* hushmap using uthash */
struct map {
    int id;                    /* key */
    UT_hash_handle hh;         /* makes this structure hashable */
};

int longestConsecutive(int* nums, int numsSize) {
    int max = 0;
    struct map *numsmap = NULL;
    struct map *s, *t;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(numsmap, &nums[i], s);  /* id already in the hash? */
        if (s == NULL) {
            s = (struct map *)malloc(sizeof *s);
            s->id = nums[i];
            HASH_ADD_INT(numsmap, id, s);  /* id: name of key field */
        }
    }

    for (s = numsmap; s != NULL; s = s->hh.next) {
        int num = s->id - 1;
        HASH_FIND_INT(numsmap, &num, t);
        if (t == NULL) {
            int count = 1;
            num = s->id + 1;
            while(true) {
                HASH_FIND_INT(numsmap, &num, t);
                if (t == NULL) {
                    if (count > max) max = count;
                    break;
                }
                count++;
                num++;
            }
        }
    }

    HASH_ITER(hh, numsmap, s, t) {
        HASH_DEL(numsmap, s);
        free(s);
    }
    return max;
}