int strStr(char * haystack, char * needle){
    int m, n;
    if (needle[0] == 0)
        return 0;   
    m = strlen(haystack);
    n = strlen(needle);
    int i, j;
    if (m < n)
        return -1;
    
    for (i = 0; ;i++) {
        for (j = 0; ;j++) {
            if(j == n) return i;       //found
            if((i+j) == m) return -1;
            if(haystack[i+j] != needle[j]) break;
        }
    }
}