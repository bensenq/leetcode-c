int compress(char* chars, int charsSize) {
    int i = 1, j = 0;
    int repeat = 1;
    int last = chars[0];
    char count[5];
    while(i <= charsSize) {
        if (i < charsSize && chars[i] == last) {
            repeat++;
        } else {
            // printf("last:%c, repeat:%d\n", last, repeat);
            chars[j] = last;
            j++;
            if (repeat > 1) {
                int len;
                memset(count, 0, 5);
                sprintf(count, "%d", repeat);
                len = strlen(count);
                memcpy(chars+j, count, len);
                j += len;
            }
            if (i < charsSize) {
                last = chars[i];
                repeat = 1;
            }
        }
        i++;
    }
    return j;
}
