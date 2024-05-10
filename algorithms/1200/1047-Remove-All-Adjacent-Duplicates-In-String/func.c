char * removeDuplicates(char * s){
    int i = 0, j = 0;
    char c;
    while(c = s[i]) {
        if(j != 0 && c == s[j-1]) {
            j = j-1;
        } else {
            s[j] = s[i];
            j++;
        }
        i++;
    }
    s[j] = 0;
    return s;
}