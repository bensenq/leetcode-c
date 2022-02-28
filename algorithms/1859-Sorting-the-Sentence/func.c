char * sortSentence(char * s){
    char *hash[9] = {0};
    char *result;
    char num;
    int start = 0;
    int i = 0, j, l;
    while(s[i] != 0) {
        if (s[i] != ' ') {
            if (s[i] >= '1' && s[i] <= '9') {
                char *tmp;
                num = s[i] - '1';
                l = i - start + 1;
                tmp = malloc(l);
                memcpy(tmp, &s[start], l-1);
                tmp[l-1] = 0;
                hash[num] = tmp;
            }
        } else {
            start = i+1;
        }
        i++;
    }

    result = malloc(sizeof(int) * i);   //i is str lenth.
    j = 0;
    for (i = 0; i < 9; i++) {
        if (hash[i] == 0)
            break;
        else {
            if (j != 0) {
                result[j] = ' ';
                j++;
            }
            strcpy(&result[j], hash[i]);
            j = j + strlen(hash[i]);
            //to do: free(hash[i]);
        }
    }
    return result;
}