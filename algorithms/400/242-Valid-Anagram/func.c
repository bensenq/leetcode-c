bool isAnagram(char* s, char* t) {
    if(strlen(s) != strlen(t)) return false;
    int len = strlen(s);
    int *freqs = calloc(26, sizeof(int));
    int *freqt = calloc(26, sizeof(int));
    for(int i = 0; i < len; i++) {
        freqs[s[i] - 'a']++;
        freqt[t[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if (freqs[i] != freqt[i]) return false;
    }
    return true;
}
