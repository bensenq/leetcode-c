bool isPalindrome(char* s) {
    int len = strlen(s);
    char *sdup = malloc(len);
    int i = 0, j = 0;
    while(i < len) {
        if (s[i] >= '0' && s[i] <= '9' ||
            s[i] >= 'a' && s[i] <= 'z') {
            sdup[j] = s[i];
            j++;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            sdup[j] = s[i] - ('A' - 'a');
            j++;
        }
        i++;
    }
    for (int k = 0; k < j/2; k++) {
        if (sdup[k] != sdup[j-1-k])
            return false;
    }
    free(sdup);
    return true;
}