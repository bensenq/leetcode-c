int mySqrt(int x){
    unsigned long min = 0, max = x;
    unsigned long mid;
    int result;
    if (x == 0 || x == 1) return x;
    while (true) {
        if (min == max-1) {
            result = min;
            break;
        } else {
            mid = (min + max) / 2;
            if (mid * mid > x) {
                max = mid;
            } else if (mid * mid < x) {
                min = mid;
            } else {
                result = mid;
                break;
            }
        }
    }
    return result;
}