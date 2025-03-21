int minAddToMakeValid(char* s) {
    int count = 0;
    int stacksize = 0;
    while(*s) {
        if(*s == '(')stacksize++;
        if(*s == ')') {
            if (stacksize == 0) count++;
            else stacksize--;
        }
        s++;
    }
    return stacksize+count;    
}