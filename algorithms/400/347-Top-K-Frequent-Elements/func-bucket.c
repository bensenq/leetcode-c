/* uthash and bucket */

/* uthash structure */
struct my_struct {
    int id;            /* key */
    int freq;           /* frequency */
    UT_hash_handle hh;  /* makes this structure hashable */
};

/* bucket: simple dynamic array */
struct bucket {
    int *data;
    int len;
    int cap;
};

void initBucket(struct bucket *b) {
    b->len = 0;
    b->cap = 1;
    b->data = malloc(sizeof(int) * b->cap);
}

void deinitBucket(struct bucket *b) {
    free(b->data);
}

int popBucket(struct bucket* b) {
    b->len--;
    return b->data[b->len];
}
void pushBucket(struct bucket *b, int id) {
    if (b->len == b->cap) {
        b->cap *= 2;
        b->data = realloc(b->data, sizeof(int) * b->cap);
    }
    b->data[b->len] = id;
    b->len++;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *result = malloc(sizeof(int) * k);
    struct my_struct *users = NULL;    /* important! initialize to NULL */
    struct my_struct *s, *tmp;
    for(int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(users, &nums[i], s);
        if (s == NULL) {
            s = (struct my_struct *)malloc(sizeof *s);
            s->id = nums[i];
            s->freq = 1;
            HASH_ADD_INT(users, id, s);  /* id: name of key field */
        } else {
            s->freq += 1;
        }
    }
    // HASH_ITER(hh, users, s, tmp) {
    //     printf("user id %d: freq %d\n", s->id, s->freq);
    //     /* ... it is safe to delete and free s here */
    // }
    struct bucket *buckets = malloc(sizeof(struct bucket) * (numsSize + 1));
    for(int i = 1; i <= numsSize; i++) {
        initBucket(&buckets[i]);
    }
    HASH_ITER(hh, users, s, tmp) {
        // printf("user id %d: freq %d\n", s->id, s->freq);
        /* ... it is safe to delete and free s here */
        HASH_DEL(users,s);
        pushBucket(&buckets[s->freq], s->id);
        free(s);
    }   
    int j = 0;
    for (int i = numsSize; i > 0; i--) {
        while(buckets[i].len > 0) {
            result[j] = popBucket(&buckets[i]);
            // printf("id:%d, freq:%d\n",result[j], i);
            j++;
            if (j == k) break;
        }
        if (j == k) break;
    }

    for(int i = 1; i <= numsSize; i++) {
        deinitBucket(&buckets[i]);
    }
    free(buckets);

    *returnSize = k;
    return result;
}