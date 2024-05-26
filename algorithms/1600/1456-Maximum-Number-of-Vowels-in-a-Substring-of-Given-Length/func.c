int maxVowels(char* s, int k) {
    int i = 0;
    int count = 0;
    int max = 0;
    while(i < k) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' 
            || s[i] == 'o' || s[i] == 'u') {
            count++;
        }
        i++;
    }
    if (count == k) return k;
    max = count;

    while(s[i] != 0) {
        if (s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' 
            || s[i-k] == 'o' || s[i-k] == 'u') count--;
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' 
            || s[i] == 'o' || s[i] == 'u') count++;
        if (count > max) {
            if (count == k) return k;
            max = count;
        }
        i++;
    }
    return max;
}