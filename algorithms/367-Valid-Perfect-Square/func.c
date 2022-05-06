bool isPerfectSquare(int num){
    unsigned long min = 0, max = num;
    unsigned long mid;
    int result;
    if (num == 0 || num == 1) return true;
    while (true) {
        if (min == max-1) {
            result = false;
            break;
        } else {
            mid = (min + max) / 2;
            if (mid * mid > num) {
                max = mid;
            } else if (mid * mid < num) {
                min = mid;
            } else {
                result = true;
                break;
            }
        }
    }

    return result;
}