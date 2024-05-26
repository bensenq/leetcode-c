char* reverseWords(char* s) {
    int n = strlen(s);
    char *ans = malloc(n+1);
    int i = n - 1, j = 0;
    int end = -1, start;
    while (i >= 0) {
        if (s[i] == ' ') {
            if (end != -1) {
                memcpy(ans+j, s+i+1, (end-i));
                ans[j+end-i] = ' ';
                j += end - i + 1;
                end = -1;
            }
        } else {    /* s[i] != ' ' */
            if (end == -1)
                end = i;
        }
        i--;
    }
    if(end != -1) {
        memcpy(ans+j, s, (end+1));
        ans[j+end+1] = ' ';
        j += end + 2;
    }
    ans[j-1] = 0;
    ans = realloc(ans, j);
    return ans;
}
