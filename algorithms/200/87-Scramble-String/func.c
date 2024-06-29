/* recursive + memo */

// caution: demo hash code, not consider the collision case
unsigned int simple_string_hash(const char *s1, const char *s2) {
    unsigned int hash = 0;
    unsigned int p = 31;
    while (*s1) {
        hash = (hash * p + (unsigned char)(*s1)) % 9997;
        s1++;
    }
    while (*s2) {
        hash = (hash * p + (unsigned char)(*s2)) % 9997;
        s2++;
    }
    return hash;
}

bool isScrambleMemo(char* s1, char* s2, char *hashmap) {
    unsigned int hash = simple_string_hash(s1, s2);
    if (hashmap[hash] == 1) return true;
    if (hashmap[hash] == 2) return false;

    if (strcmp(s1, s2) == 0) return true; 
    int n = strlen(s1);

    int letters[26] = {0};
    for (int i = 0; i < n; i++) {
        letters[s1[i]-'a']++;
        letters[s2[i]-'a']--;
    }
    for (int i = 0; i < 26; i++) if (letters[i] != 0) {
        hashmap[hash] = 2;  // record false;
        return false;
    }

    for (int i = 1; i < n; i++) {
        if (isScrambleMemo(strndup(s1, i), strndup(s2, i), hashmap) 
            && isScrambleMemo(strndup(s1+i,n-i), strndup(s2+i,n-i), hashmap)) {
                hashmap[hash] = 1;  // record true;
                return true;
            } 
        if (isScrambleMemo(strndup(s1, i), strndup(s2+n-i, i), hashmap) 
            && isScrambleMemo(strndup(s1+i,n-i), strndup(s2, n-i), hashmap)) {
                hashmap[hash] = 1;  // record true;
                return true;
            }
    }
    hashmap[hash] = 2;  // record false;
    return false;
}

bool isScramble(char* s1, char* s2) {
    char *hashmap = calloc(1, 10000);
    return isScrambleMemo(s1, s2, hashmap);
}