bool isHappy(int n) {
    unsigned long long *bitmap = calloc(64, 730/64+1);
    bool ans = false;
    while(1) {
        int sum = 0;
        while(n > 0) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        if (sum == 1) {
            ans = true;
            break;
        } else {
            int index = sum / 64;
            int offset = sum % 64;
            if (bitmap[index] & 0x1ULL << offset) break;
            else bitmap[index] |= 0x1ULL << offset;
        }
        n = sum;
    }
    free(bitmap);
    return ans;
}