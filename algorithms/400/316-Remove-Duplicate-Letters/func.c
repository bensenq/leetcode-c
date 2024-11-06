char* removeDuplicateLetters(char* s) {
    int lastIndex[26];
    bool seen[26];
    int n = strlen(s);
    for (int i = 0; i < 26; i++) {
        lastIndex[i] = 0;
        seen[i] = false;
    }
    for (int i = 0; i < n; i++) {
        lastIndex[s[i] - 'a'] = i;
    }
    
    char stack[27];
    int top = -1;

    for (int i = 0; i < n; i++) {
        int curr = s[i] - 'a';
        if (seen[curr]) continue;
        while (top != -1 && stack[top] > s[i] && i < lastIndex[stack[top] - 'a']) {
            seen[stack[top] - 'a'] = false;
            top--;
        }
        stack[++top] = s[i];
        seen[curr] = true;
    }
    stack[++top] = 0;
    return strdup(stack);
}