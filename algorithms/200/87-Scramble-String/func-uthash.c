/* recursive + memo using uthash */

struct hashScramble {
    const char *key;          /* key: s1+s2 */
    bool isScramble;            
    UT_hash_handle hh;         /* makes this structure hashable */
};

bool isScrambleCore(char* s1, char* s2, struct hashScramble** users) {
    struct hashScramble *s = NULL, *tmp;
    char* key = calloc(strlen(s1)*2+1, 1);
    key = strcat(key, s1);
    key = strcat(key, s2);
    HASH_FIND_STR( *users, key, s);
    if (s) {
        printf("found\n");
        return s->isScramble;
    }

    if (strcmp(s1, s2) == 0) return true; 
    int n = strlen(s1);

    int letters[26] = {0};
    for (int i = 0; i < n; i++) {
        letters[s1[i]-'a']++;
        letters[s2[i]-'a']--;
    }
    for (int i = 0; i < 26; i++) { 
        if (letters[i] != 0) {
            s = malloc(sizeof(struct hashScramble));
            s->key = key;
            s->isScramble = false;
            HASH_ADD_KEYPTR(hh, *users, s->key, strlen(s->key), s);
            return false;
        }
    }

    for (int i = 1; i < n; i++) {
        if (isScrambleCore(strndup(s1, i), strndup(s2, i), users) 
            && isScrambleCore(strndup(s1+i,n-i), strndup(s2+i,n-i), users)) {
                s = malloc(sizeof(struct hashScramble));
                s->key = key;
                s->isScramble = true;
                HASH_ADD_KEYPTR(hh, *users, s->key, strlen(s->key), s);
                return true;
            } 
        if (isScrambleCore(strndup(s1, i), strndup(s2+n-i, i), users) 
            && isScrambleCore(strndup(s1+i,n-i), strndup(s2, n-i), users)) {
                s = malloc(sizeof(struct hashScramble));
                s->key = key;
                s->isScramble = true;
                HASH_ADD_KEYPTR(hh, *users, s->key, strlen(s->key), s);
                return true;
            }
    }
    s = malloc(sizeof(struct hashScramble));
    s->key = key;
    s->isScramble = false;
    HASH_ADD_KEYPTR(hh, *users, s->key, strlen(s->key), s);
    return false;
}

bool isScramble(char* s1, char* s2) {
    struct hashScramble *users = NULL;  // hash head
    return isScrambleCore(s1, s2, &users);
}