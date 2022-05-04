int apow(int a, int b) {
    int pow = 1;
    for (int i = 0; i < b; i++) {
        pow = (a * pow) % 1337;
    }
    return pow;
}
int superPow(int a, int* b, int bSize) {
    int sum = 1;
    a = a % 1337;
    for (int i = 0; i < bSize; i++) {
        sum = sum * apow(a, b[bSize - 1 - i]) % 1337;
        a = apow(a, 10) % 1337;
    }
    return sum;
}