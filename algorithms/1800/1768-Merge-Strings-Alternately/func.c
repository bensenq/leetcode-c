char * mergeAlternately(char * word1, char * word2){
    int len = strlen(word1)+strlen(word2)+1;
    char *merged = malloc(len);
    int i = 0, j = 0, k = 0;
    merged[len-1] = 0;
    while(i < len - 1){
        if(word1[j] != 0) merged[i++] = word1[j++];
        if(word2[k] != 0) merged[i++] = word2[k++];
    }
    return merged;
}