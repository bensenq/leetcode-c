bool divisorOfString(char *str, int len, int n) {
    for (int i = 1; i < len / n; i++) {
        for (int j = 0; j < n; j++) {
            if(str[i*n+j] != str[j]) return false;
        }
    }
    return true;
}

char* gcdOfStrings(char* str1, char* str2) {
    int same = 0;
    int i = 0;
    int n1 = strlen(str1), n2 = strlen(str2);
    while (str1[i] && str2[i]) {
        if(str1[i] == str2[i]) { same++; i++; }
        else break;
    }
    for (i = same; i > 0; i--) {
        if (n1 % i == 0 && n2 % i == 0) {
            if (divisorOfString(str1, n1, i) && divisorOfString(str2, n2, i))
                return strndup(str1, i);
        }
    }

    return "";
}