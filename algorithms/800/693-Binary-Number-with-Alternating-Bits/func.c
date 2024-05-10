bool hasAlternatingBits(int n){
    int expect = n & 1;
    while(n != 0) {
        expect ^= 1;
        n >>= 1;
        if ((n & 1) != expect) return false;
    }
    return true;
}