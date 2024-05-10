int compareVersion(char* version1, char* version2) {
    int result = 0;
    char *str1, *str2, *saveptr1, *saveptr2, *token1, *token2;
    int end1 = 0, end2 = 0;
    int val1, val2;
    for (str1 = version1, str2 = version2; ;str1 = NULL, str2 = NULL) {
        if (!end1) {
            token1 = strtok_r(str1, ".", &saveptr1);
            if(token1 == NULL) { val1 = 0; end1 = 1;}
            else val1 = atoi(token1);
        }
        if (!end2) {
            token2 = strtok_r(str2, ".", &saveptr2);
            if(token2 == NULL) { val2 = 0; end2 = 1;}
            else val2 = atoi(token2);
        }
        if (end1 && end2) break;
        if (val1 > val2) {
            result = 1;
            break;
        } else if (val1 < val2) {
            result = -1;
            break;
        }
    }
    return result;
}