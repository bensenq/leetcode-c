

char * reformat(char * s){
    char alpha[500];
    char number[500];
    char *result;
    char *first, *second;
    int m = 0, n = 0;
    int i = 0, j;
    while(s[i] != 0) {
        if(s[i] >= 'a') 
            alpha[m++] = s[i];
        else
            number[n++] = s[i];
        i++;
    }
    
    /* not possible */
    if ((m - n) > 1 || (m - n) < -1)
        return "";
    
    result = malloc(i+1);
    result[i] = 0;
    
    if (m >= n) {
        first = alpha;
        second = number;
    } else {
        first = number;
        second = alpha;
    }
    
    for (i = 0, j = 0; i <(m+n); i+=2, j++) {
        result[i] = first[j];
    }
    
    for (i = 1, j = 0; i <(m+n); i+=2, j++) {
        result[i] = second[j];
    }
    
    return result;
}