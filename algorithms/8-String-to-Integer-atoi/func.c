#define MAX ((1LL << 31) - 1)
#define MIN (-(1LL << 31))

int myAtoi(char * s){
    int i = 0;
    int sign = 1;   //default postive
    char number[11];
    long long value;
    int result;
    int len = 0;
    long long step;
    //step 1: process leading space
    while (s[i] != 0) {
        if (s[i] != ' ') {
            break;
        }
        i++;
    }
    
    //step 2: process sign
    if (s[i] != 0 && (s[i] =='-' || s[i] == '+')) {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }
    
    //step 3: process leading zero 
    while (s[i] != 0 && s[i] == '0') {    
        i++;
    }
    
    //step 4: get input value
    while (s[i] != 0) {    
        if (s[i] >= '0' && s[i] <= '9') {
            number[len] = s[i] - '0';
            len++;i++;
            if (len == 11)  //overflow
                break;
        } else {
            break;  //non-digital
        }
    }
    
    if (len == 11) {
        if (sign == 1)
            result = MAX;
        else
            result = MIN;
    } else {
        i = len-1;
        value = 0;
        step = 1;
        while(i >= 0) {
            value += number[i] * step;
            step = step * 10;
            i--;
        }

        value = sign * value;
        if (value < MIN)
            value = MIN;
        else if (value > MAX)
            value = MAX;
        result = value;
    }
    return result;
}