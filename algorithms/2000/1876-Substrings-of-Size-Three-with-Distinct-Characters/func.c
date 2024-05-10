int countGoodSubstrings(char * s){
    int count = 0;
    char c;
    int set = 1;
    int i = 1;
    while(c = s[i]) {
        if (c != s[i-1]) {
            if (set == 1) {
                set = 2;
            } else if (set == 2 && c !=  s[i-2]) {
                count++;
            }
        } else {
            set = 1;
        }
        i++;
    }
    return count;
}