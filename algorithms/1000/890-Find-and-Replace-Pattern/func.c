//base on Problem 205

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
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize) {
    int count = 0;
    char **res = malloc(sizeof(char*)*wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        if (isIsomorphic(words[i], pattern)) {
            res[count++] = words[i];
        }
    }
    *returnSize = count;
    return res;
}