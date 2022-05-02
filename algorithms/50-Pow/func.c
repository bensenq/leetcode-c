double myPow(double x, int n){
    int signx, signn;
    long absn, longn = n;
    double absx, result;
    long i;
    if (n == 0)
        return 1;
    
    signn = n > 0 ? 1 : -1;
    signx = x > 0 ? 1 : -1;
    absn = longn > 0 ? longn : -longn;
    absx = x > 0 ? x : -x;
    
    result = absx;
    if (absx == 1)
        goto process_sign;
    
    for (i = 2; i <= absn; i *= 2) {
        result *= result;
    }
    result *= myPow(absx, absn - (i/2));
    
process_sign:
    if (signn == -1) {
        result = 1 / result;
    }
    
    if (signx == -1) {
        if (absn & 1) {
            result = -result;
        }
    }
    
    return result;
}