char * getPermutation(int n, int k){
    int factorial[n];     //factorial[n] is useless
    int number[n+1];      //number[0] is not used;
    char *result = malloc(n+1);
    int count = 0;
    int remain = k - 1;

    for (int i = 1; i <= n; i++) {
        number[i] = 1;  // init to all valid;
    }
    
    factorial[0] = 1;   //factorial[0] set to 1
    for (int i = 1; i < n; i++) {
        factorial[i] = factorial[i-1] * i;
    }

    while (count < n) {
        int index = remain / factorial[n-1-count];
        remain = remain % factorial[n-1-count];
        for (int i = 0, j = 1; j <= n; j++) {
            if (number[j] != 0) {
                i++;
                if (i > index) {
                    number[j] = 0;
                    result[count] = '0' + j;
                    break;
                }
            }
        }
        count++;
    }
    result[n] = 0;
    return result;
}