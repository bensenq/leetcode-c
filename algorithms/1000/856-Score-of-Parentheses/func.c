int score(char *s, int *index) {
    int value = 0;
    while(s[*index] == '(') {   //save level
        *index += 1;
        if (s[*index] == '(') {
            value += 2 * score(s, index);   // next level
            *index += 1;
        } else {
            if (s[*index - 1] == '(') {
                value += 1;
            }
            *index += 1;
        }
    }
    return value;
}
int scoreOfParentheses(char* s) {
    int index = 0;
    int ans = score(s, &index);
    return ans;   
}
