// https://leetcode.com/problems/number-of-digit-one/?envType=problem-list-v2&envId=dynamic-programming
// Go through the digit positions one at a time, find out how often a "1" appears at each position, and sum those up
int countDigitOne(int n) {
    int ones = 0;
    for (long long m = 1; m <= n; m *= 10) {
        int a = n / m, b = n % m;
        ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    }
    return ones;
}