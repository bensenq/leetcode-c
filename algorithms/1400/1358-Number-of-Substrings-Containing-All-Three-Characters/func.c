// sliding window
int numberOfSubstrings(char* s) {
    int freq[3] = {0};
    int classes = 0;
    int start = 0, end = 0;
    int count = 0;
    int len = strlen(s);
    while(end < len) {
        while(classes < 3) {
            if (end == len) break;
            char c = s[end];
            freq[c-'a']++;
            if(freq[c-'a'] == 1) classes++;
            end++;
        }

        while(classes == 3) {
            count += len - end + 1;
            char c = s[start];
            freq[c-'a']--;
            if(freq[c-'a'] == 0) classes--;
            start++;
        }
    }

    return count;
}