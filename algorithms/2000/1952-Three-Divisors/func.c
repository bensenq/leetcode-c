bool isThree(int n) {
    if (n <= 2) return false;
    int s = floor(sqrt(n));
    if (s * s != n) return false;
    int i = 2;
    while(i < s) {
        if (n % i == 0) return false;
        i++;
    }
    return true;
}