int countLargestGroup(int n) {
    int *freq = calloc(37, 4);
    int digitsSum = 0;
    int digits[5] = {0, 0, 0, 0, 0};
    for(int i = 1; i <= n; i++) {
        if(i % 10000 == 0) {
            digitsSum -= 35;
        } else if (i % 1000 == 0) {
            digitsSum -= 26;
        } else if (i % 100 == 0) {
            digitsSum -= 17;
        } else if (i % 10 == 0) {
            digitsSum -= 8;
        } else {
            digitsSum += 1;
        }
        freq[digitsSum]++;
    }

    int maxfreq = 0;
    int result = 0;
    for(int i = 1; i <= 36; i++) {
        if (freq[i] > maxfreq) {
            maxfreq = freq[i];
            result = 1;
        } else if (freq[i] == maxfreq) {
            result++;
        }
    }
    return result;    
}
