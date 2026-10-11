char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    char *res = malloc(n);
    int size = 0;
    int depth = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            if(depth != 0) res[size++] = '(';
            depth++;
        } else {
            if(depth != 1) res[size++] = ')';
            depth--;
        }
    }
    res[size++] = 0;
    res = realloc(res, size);
    return res;
}
