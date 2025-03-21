int rangeBitwiseAnd(int left, int right) {
    if (left == right) return left;
    int tmp = left;
    int shift = 0;
    int ans = 0;

    while(tmp > 0) {
        if (tmp & 1 != 0) {
            unsigned int val = (unsigned int)left + (1 << shift);
            if ((val >> shift << shift) > right) {
                break;
            }
        }
        shift += 1;
        tmp >>= 1;
    }
    return left & (~((1 << shift) - 1));
}