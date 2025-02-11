char* clearDigits(char* s) {
    char *out = strdup(s);
    int i = 0, j = 0;
    while(s[i] != 0) {
        if (isdigit(s[i])) {
            j--;
        } else {
            out[j++] = s[i];
        }
        i++;
    }
    out[j] = 0;
    return out;
}