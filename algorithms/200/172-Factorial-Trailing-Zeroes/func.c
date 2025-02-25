//Math: all trailing 0 is from factors 5 * 2,
//number of factors of 2 in n is more than 5, so we can ignore it.
//calculates the number of factors of 5 in n!

int trailingZeroes(int n) {
    int count = 0;
    while(n >= 5){
        count += n / 5;
        n /= 5;
    };
    return count;
};