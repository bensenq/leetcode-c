

int divide(int dividend, int divisor){
    int sign_dividend, sign_divisor;
    long long abs_dividend, abs_divisor;
    long long result = 0;
    long long sub, counter;
    sign_dividend = dividend > 0 ? 1 : -1;
    sign_divisor = divisor > 0 ? 1 : -1;
    abs_dividend = dividend > 0 ? dividend : -(long long)dividend;
    abs_divisor = divisor > 0 ? divisor : -(long long)divisor;
    sub = abs_divisor;
    counter = 1;
    while (abs_dividend >= abs_divisor) {
        if (abs_dividend >= sub) {
            abs_dividend -= sub;
            result += counter;
            sub = sub << 1;
            counter = counter << 1;
        } else {
            sub = sub >> 1;
            counter = counter >> 1;
        }
    }
    
    if (sign_dividend != sign_divisor)
        result = -result;
    if (result > 2147483647)
        result = 2147483647;
    return result;
}