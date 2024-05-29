bool closeStrings(char* word1, char* word2) {
    int n1 = strlen(word1);
    int n2 = strlen(word2);
    if (n1 != n2) return false;
    int hash1[26] = {0}, hash2[26] = {0};
    int set1[26] = {0}, set2[26] = {0}; 
    int c1 = 0, c2 = 0;
    int index, i, j;
    for (i = 0; i < n1; i++) {
        index = word1[i] - 'a';
        hash1[index]++;
        if (set1[index] == 0) {
            set1[index] = 1;
            c1++;
        }
    }
    for (i = 0; i < n2; i++) {
        index = word2[i] - 'a';
        hash2[index]++;
        if (set1[index] != 1) return false; /* check char exist in word1 */
        if (set2[index] == 0) {
            set2[index] = 1;
            c2++;
        }
    }
    if (c1 != c2) return false;
    for (i = 0; i < 26; i++) {
        if (set1[i] != 0) {
            for (j = 0; j < 26; j++) {
                if (set2[j] != 0 && hash1[i] == hash2[j]) {
                    set2[j] = 0;
                    break;
                }
            }
            if (j == 26) return false;
        }
    }
    return true;
}