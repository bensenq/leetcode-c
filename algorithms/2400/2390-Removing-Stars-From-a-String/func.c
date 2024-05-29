char* removeStars(char* s) {
    int i = 0, j = 0;
    int n = strlen(s);
    char *result = malloc(n+1);
    while(i < n) {
        if (s[i] == '*') j--;
        else result[j++] = s[i];
        i++;
    }
    result[j] = 0;
    result = realloc(result, j+1);
    return result;
}