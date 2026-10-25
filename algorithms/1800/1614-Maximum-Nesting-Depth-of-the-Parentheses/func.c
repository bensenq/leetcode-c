int maxDepth(char* s) {
    int ans = 0;
    int depth = 0;
    int i = 0;
    while(s[i] != 0) {
        if(s[i] == '(') {
            depth++;
            if(depth > ans) ans = depth;
        } else if(s[i] == ')') {
            depth--;
        }
        i++;
    }
    return ans;
}
