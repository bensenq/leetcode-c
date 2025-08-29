char* largestGoodInteger(char* num) {
    int largestGoodDigit = -1;
    int dupped = 0;
    int i = 1;
    while(num[i] != 0) {
        if (num[i] == num[i-1]) {
            if (dupped) {
                dupped = 0;
                if (num[i] - '0' > largestGoodDigit) {
                    largestGoodDigit = num[i] - '0';
                }
            } else {
                dupped = 1;
            }
        } else {
            if (dupped) {
                dupped = 0;
            }
        }
        i++;
    }
    if (largestGoodDigit != -1) {
        char *result = calloc(4, 1);
        result[0] = result[1] = result[2] = largestGoodDigit + '0';
        return result;
    }
    else
        return "";
}
