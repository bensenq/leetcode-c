int lengthOfLastWord(char * s){
    int len = 0;
    int result = 0;
    int i = 0;
    while(s[i] != 0) {
        if (s[i] == ' ') {
            if (len != 0) {
                result = len;
                len = 0;
            }
        } else {
            len++;
        }
        i++;
    }
    if (len != 0) {
        result = len;
        len = 0;
    }
    return result;
}