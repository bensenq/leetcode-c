#define max(a,b) (a > b ? a : b)
#define BITS_PER_LONG (sizeof(unsigned long) * 8)

char * addBinary(char * a, char * b){
    int i, j, start;
    int lenA = strlen(a);
    int lenB = strlen(b);
    int lenResult = max(lenA, lenB);
    char *result = malloc(lenResult+1);
    int lenLongA = (lenA + BITS_PER_LONG - 1) / BITS_PER_LONG;
    int lenLongB = (lenB + BITS_PER_LONG - 1) / BITS_PER_LONG;
    int lenLongResult = max(lenLongA, lenLongB);
    unsigned long *bitsA = calloc(sizeof(unsigned long), lenLongResult);
    unsigned long *bitsB = calloc(sizeof(unsigned long), lenLongResult);
    unsigned long *bitsResult = calloc(sizeof(unsigned long), lenLongResult);
    int addone;

    for (i = lenA-1; i >= 0; i--) {
        if (a[i] == '1')
            bitsA[(lenA-1-i)/BITS_PER_LONG] |= 1UL << ((lenA-1-i) % BITS_PER_LONG);
    }

    for (i = lenB-1; i >= 0; i--) {
        if (b[i] == '1')
            bitsB[(lenB-1-i)/BITS_PER_LONG] |= 1UL << ((lenB-1-i) % BITS_PER_LONG);
    }
    
    addone = 0;
    for (i = 0; i < lenLongResult; i++) {
        bitsResult[i] = bitsA[i] + bitsB[i] + addone;
        if (bitsResult[i] < bitsA[i])
            addone = 1;
        else
            addone = 0;
    }

    start = lenResult -1;
    result[lenResult] = 0;
    if (addone == 1 || 
        ((lenResult%BITS_PER_LONG) && (bitsResult[(lenResult)/BITS_PER_LONG] & (1UL<<(lenResult)%BITS_PER_LONG)))) {
        char *tmp = result;
        result = malloc(lenResult+2);
        result[0] = '1';
        result[lenResult+1] = 0;
        free(tmp);
        start++;
    }
    i = 0;
    while (i < lenResult) {
        if (bitsResult[i/BITS_PER_LONG] & (1UL << (i%BITS_PER_LONG)))
            result[start-i] = '1';
        else
            result[start-i] = '0';
        i++;
    }
    free(bitsA);
    free(bitsB);
    free(bitsResult);
    return result;
}

int main(void) {
//    char * ret = addBinary("11001000011101111111010011101001111111110000110101000", "1010110011100010000110100011001101110001111001001010001100000100011111011011111");
    char * ret = addBinary("110010001101001011011000110101011110101011110001100", "1001101110010111101011110010100000110000011100000101011000010110");
    free(ret);
    return 0;
}