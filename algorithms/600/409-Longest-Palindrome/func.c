int longestPalindrome(char * s){
    int freq[128] = {0};
    char index, c;
    int sum = 0, num_odd = 0;
    int i;
    for (i = 0; c = s[i]; i++) {
        freq[c]++;
    }

    for (i = 'a'; i <= 'z'; i++) {
        int count = freq[i];
        if (count > 0) {
            sum += count;
            if (count % 2) {
                num_odd++;
            }
        }
    }

    for (i = 'A'; i <= 'Z'; i++) {
        int count = freq[i];
        if (count > 0) {
            sum += count;
            if (count % 2) {
                num_odd++;
            }
        }
    }

    if (num_odd) {
        sum = sum - num_odd + 1;
    }

    return sum;
}