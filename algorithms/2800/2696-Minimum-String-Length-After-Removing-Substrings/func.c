/* stack-based */
int minLength(char * s){
    int len = strlen(s);
    int count = 0;
    char stack[len];
    int size = 0;
    while(*s != 0) {
        if (*s == 'A' || *s == 'C') {
            stack[size] = *s;
            size++;
        } else if (*s == 'B' && size > 0 && stack[size-1] == 'A' ||
                   *s == 'D' && size > 0 && stack[size-1] == 'C') {
            count++;
            size--;
        } else {
            size = 0;
        }
        s++;
    }
    return len - count*2;
}