bool isSubsequence(char * s, char * t){
    int i = 0, j = 0;
    int lens = strlen(s);
    int lent = strlen(t);
    if (lens == 0)
        return true;
    while (i < lent) {
        if (i + (lens - j) > lent)
            break;
        if (t[i] == s[j])
            j++;
        if (j == lens)
            return true;
        i++;
    }
    return false;
}