bool isIsomorphic(char* s, char* t) {
    char hash[128] = {0};
    char used[128] = {0};
    int i = 0;
    while(s[i] != 0) {
        if (hash[s[i]] == 0) {
            if (used[t[i]] != 0) return false;
            hash[s[i]] = t[i];
            used[t[i]] = 1;
        } else {
            if (hash[s[i]] != t[i]) return false;
        }
        i++;
    }
    return  true;
}