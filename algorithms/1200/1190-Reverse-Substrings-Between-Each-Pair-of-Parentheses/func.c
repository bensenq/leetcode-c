void parseStr(char *s, int *index, char *ans, int *size) {
    while(s[*index] != ')' && s[*index] != 0) {
        if (s[*index] != '(') {
            ans[*size] = s[*index];
            *size+=1; 
            *index += 1;
        } else if(s[*index] == '(') {
            *index += 1;
            int start = *size;
            parseStr(s, index, ans, size);
            int stop = *size;
            *index += 1;
            int left = start, right = stop - 1, temp;
            while(left < right) {
                temp = ans[left];
                ans[left] = ans[right];
                ans[right] = temp;
                left++; right--;
            }
        }
    }
    return;
}
char* reverseParentheses(char* s) {
    int n = strlen(s);
    int index = 0, size = 0;
    char* ans = malloc(n+1);
    parseStr(s, &index, ans, &size);
    ans[size] = 0;
    ans = realloc(ans, size+1);
    return ans;
}
