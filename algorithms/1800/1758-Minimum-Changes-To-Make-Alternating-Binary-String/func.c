int minOperations(char* s) {
    int min = 0;
    int len = 0;
    char expect = '0';
    char add = 1;
    while(s[len] != 0) {
        if (s[len] != expect) min++;
        expect += add;
        add = -1 * add;
        len++;
    }
    if (min > len - min) min = len - min;
    return min;
}