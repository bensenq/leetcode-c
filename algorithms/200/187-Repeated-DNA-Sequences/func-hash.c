typedef struct {
    int key;        /* 20-bit hash of a 10-letter DNA window */
    int  id;        /* 1 = seen once, 2 = already reported as duplicate */
    UT_hash_handle hh;
} entry;

/* dynamic array for the answer */
typedef struct {
    char **seq;     /* array of 10-char DNA substrings */
    int  cnt;       /* number of stored substrings */
    int  cap;       /* current capacity */
} res_t;

/* encode 10 successive bases into a 20-bit integer
   A/a = 0, C/c = 1, G/g = 2, T/t = 3
   returns -1 on illegal character */
static int encode(const char *s) {
    int v = 0;
    for (int i = 0; i < 10; ++i) {
        int b;
        switch (s[i]) {
            case 'A': case 'a': b = 0; break;
            case 'C': case 'c': b = 1; break;
            case 'G': case 'g': b = 2; break;
            case 'T': case 't': b = 3; break;
            default: return -1;
        }
        v = (v << 2) | b;
    }
    return v;
}

/* find all 10-letter DNA substrings that occur more than once
   returnSize is set to the length of the returned array */
char **findRepeatedDnaSequences(const char *s, int *returnSize) {
    entry *seen = NULL;          /* hash table for encountered windows */
    res_t  rv   = { NULL, 0, 8 };
    rv.seq = malloc(rv.cap * sizeof(char *));

    int len = strlen(s);
    for (int i = 0; i <= len - 10; ++i) {
        int key = encode(s + i);
        if (key < 0) continue;              /* skip invalid characters */

        entry *e;
        HASH_FIND_INT(seen, &key, e);
        if (!e) {                           /* first time we see this window */
            e = malloc(sizeof(*e));
            e->key = key;
            e->id  = 1;
            HASH_ADD_INT(seen, key, e);
        } else if (e->id == 1) {            /* second time – record duplicate */
            e->id = 2;
            if (rv.cnt == rv.cap) {         /* grow result array if needed */
                rv.cap <<= 1;
                rv.seq = realloc(rv.seq, rv.cap * sizeof(char *));
            }
            char *t = malloc(11);           /* copy 10 bases + '\0' */
            memcpy(t, s + i, 10);
            t[10] = '\0';
            rv.seq[rv.cnt++] = t;
        }
        /* id == 2  => already reported, nothing to do */
    }

    /* free the hash table */
    entry *cur, *tmp;
    HASH_ITER(hh, seen, cur, tmp) {
        HASH_DEL(seen, cur);
        free(cur);
    }

    *returnSize = rv.cnt;
    return rv.seq;
}
