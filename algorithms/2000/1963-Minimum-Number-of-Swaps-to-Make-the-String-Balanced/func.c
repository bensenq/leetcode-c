int minSwaps(char* s) {
    int stacksize = 0;
    int reverse = 0;
    while(*s != 0) {
        if (*s == '[')
            stacksize++;
        else {
            if (stacksize > 0) stacksize--;
            else reverse++;
        }
        s++;
    }
    if (reverse == 0) return 0;
    else return (stacksize + 1) / 2;
}