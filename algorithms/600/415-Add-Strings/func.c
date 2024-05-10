#define max(a,b) (a > b ? a : b)

char * addStrings(char * num1, char * num2){
    int i, j, k;
    int lenA = strlen(num1);
    int lenB = strlen(num2);
    int lenResult = max(lenA, lenB);
    char carry = 0;
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
            ai = num1[i];
        
        if (j < 0)
            bj = '0';
        else
            bj = num2[j];
        
        sum = (ai - '0') + (bj - '0') + carry;
        carry = sum / 10;
        result[k] = sum % 10 + '0';
        i--;j--;k--;
    }
    
    if (carry) {
        char *tmp = result;
        result = malloc(lenResult+2);
        result[0] = '1';
        memcpy(&result[1], tmp, lenResult+1);
        free(tmp);
    }
    
    return result;
}