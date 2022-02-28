

bool checkString(char * s){
    int i = 0;
    int lasta = -1, firstb = -1;
    while(s[i] != 0) {
        if (s[i] == 'a') {
            lasta = i;
            if (firstb != -1)
                return false;
        }
        if (s[i] == 'b' && firstb == -1) {
            firstb = i;
        }
        i++;
    }
    /* no voilation */
    return true;
}