/* stack */
char* decodeString(char* s) {
    int n = strlen(s);
    int size = 2 * n;
    char *result = malloc(size+1);
    int i = 0, j = 0;
    int stack[20][2], top = 0;
    while (s[i] != 0) {
        if (s[i] >= '0' && s[i] <= '9') {
            int ds = i;
            while (s[i] != '[') i++;
            stack[top][0] = atoi(strndup(&s[ds], i-ds));
            stack[top][1] = j;
            top++;
            i++;
        } else if (s[i] >= 'a' &&  s[i] <= 'z') {
            result[j++] = s[i++];
        } else if (s[i] == ']') {
            int repeat = stack[top-1][0];
            int len = j - stack[top-1][1];
            while (size - j < (repeat - 1) * len) size *= 2;
            result = realloc(result, size+1);
            for (int k = 0; k < repeat - 1; k++) {
                memcpy(&result[j], &result[j-len], len);
                j += len;
            }
            top--;
            i++;
        }
    }
    result = realloc(result, j+1);
    result[j] = 0;
    return result;
}