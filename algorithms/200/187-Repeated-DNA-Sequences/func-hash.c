typedef struct {
    uint32_t key;   /* 20-bit rolling hash */
    int      id;    /* 1=seen once, 2=duplicated */
    UT_hash_handle hh;
} entry;

typedef struct {
    char **seq;
    int  cnt;
    int  cap;
} res_t;

/* convert ACGT -> 0..3 , return -1 on illegal char */
static inline int baseBits(char c) {
    switch (c) {
        case 'A': case 'a': return 0;
        case 'C': case 'c': return 1;
        case 'G': case 'g': return 2;
        case 'T': case 't': return 3;
        default:            return -1;
    }
}

/* build initial 20-bit hash for the first 10 chars */
static uint32_t encode10(const char *s) {
    uint32_t h = 0;
    for (int i = 0; i < 10; ++i) h = (h << 2) | baseBits(s[i]);
    return h;
}

char **findRepeatedDnaSequences(const char *s, int *returnSize) {
    int len = strlen(s);
    if (len < 10) {                 /* too short */
        *returnSize = 0;
        return NULL;
    }

    entry *seen = NULL;
    res_t  rv   = {NULL, 0, 8};
    rv.seq = malloc(rv.cap * sizeof(char *));

    /* step-1: initial window */
    uint32_t h = encode10(s);
    entry *e = malloc(sizeof(*e));
    e->key = h;
    e->id  = 1;
    HASH_ADD_INT(seen, key, e);

    uint32_t mask = 0x3FFFF; /* 20 low bits */

    /* step-2: slide window one base at a time */
    for (int i = 1; i <= len - 10; ++i) {
        int out = baseBits(s[i - 1]);        /* leftmost base leaving */
        int in  = baseBits(s[i + 9]);        /* new rightmost base   */
        if (out < 0 || in < 0) continue;     /* skip invalid chars   */

        /* roll the hash: remove top 2 bits, append bottom 2 bits */
        h = ((h & mask) << 2) | in;

        HASH_FIND_INT(seen, &h, e);
        if (!e) {                           /* first time seen */
            e = malloc(sizeof(*e));
            e->key = h;
            e->id  = 1;
            HASH_ADD_INT(seen, key, e);
        } else if (e->id == 1) {            /* second time – duplicate */
            e->id = 2;
            if (rv.cnt == rv.cap) {
                rv.cap <<= 1;
                rv.seq = realloc(rv.seq, rv.cap * sizeof(char *));
            }
            char *t = malloc(11);
            memcpy(t, s + i, 10);
            t[10] = '\0';
            rv.seq[rv.cnt++] = t;
        }
    }

    /* free hash table */
    entry *cur, *tmp;
    HASH_ITER(hh, seen, cur, tmp) {
        HASH_DEL(seen, cur);
        free(cur);
    }

    *returnSize = rv.cnt;
    return rv.seq;
}
