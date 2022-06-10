char * reversePrefix(char * word, char ch){
    int i = 0, j = 0, t;
    char c;
    while(c = word[i]) {
        if (c == ch) {
            break;
        }
        i++;
    }
    
    if (c) {
        while (j < i) {
            t = word[j];
            word[j] = word[i];
            word[i] = t;
            j++; i--;
        }
    }
    
    return word;
}