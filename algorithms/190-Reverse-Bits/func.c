uint32_t reverseBits(uint32_t n) {
    int i = 0;
    uint32_t ret = 0;
    while (i < 32) {
        if (n & (1U<<i))
            ret |= 1U << (31-i);
        i++;
    }
    return ret;
}