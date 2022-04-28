#define max(a,b) (a > b ? a : b)

char * addBinary(char * a, char * b){
    int i, j, k;
    int lenA = strlen(a);
    int lenB = strlen(b);
    int lenResult = max(lenA, lenB);
    char add = 0;
    char * result = malloc(lenResult+1);
    result[lenResult] = 0;
    i = lenA - 1;
    j = lenB - 1;
    k = lenResult - 1;
    while (i >= 0 || j >= 0) {
        char ai, bj, sum;
        if (i < 0)
            ai = '0';
        else 
            ai = a[i];
        
        if (j < 0)
            bj = '0';
        else
            bj = b[j];
        
        sum = (ai - '0') + (bj - '0') + add;
        if (sum > 1)
            add = 1;
        else
            add = 0;
        result[k] = (sum & 1) + '0';
        i--;j--;k--;
    }
    
    if (add) {
        char *tmp = result;
        result = malloc(lenResult+2);
        result[0] = '1';
        memcpy(&result[1], tmp, lenResult+1);
        free(tmp);
    }
    
    return result;
}