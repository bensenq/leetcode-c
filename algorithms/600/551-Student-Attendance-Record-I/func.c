bool checkRecord(char * s){
    int As = 0;
    int conLs = 0;
    int result = true;
    while(*s != 0) {
        if (*s == 'A') {
            As++;
            conLs = 0;
            if (As == 2) {
                result = false;
                goto out;
            }
        } else if (*s == 'L') {
            conLs++;
            if (conLs == 3) {
                result = false;
                goto out;
            }
        } else {
            conLs = 0;
        }
        s++;
    }
    
out:
    return result;
}