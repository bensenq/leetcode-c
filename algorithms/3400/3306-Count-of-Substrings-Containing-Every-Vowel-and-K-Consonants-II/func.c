//Editorial Approach 1: Sliding Window
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long countOfSubstrings(char* word, int k) {
    long numValidSubstrings = 0;
    int start = 0;
    int end = 0;
    int vowelFreq[26] = {0};
    int vowelCount = 0;
    int consonantCount = 0;

    int len = strlen(word);
    int* nextConsonant = malloc(sizeof(int)*len);
    int nextConsonantIndex = len;
    for (int i = len - 1; i >= 0; i--) {
        nextConsonant[i] = nextConsonantIndex;
        if (!isVowel(word[i])) {
            nextConsonantIndex = i;
        }
    }

    while (end < len) {
        char newLetter = word[end];

        if (isVowel(newLetter)) {
            vowelFreq[newLetter - 'a']++;
            if (vowelFreq[newLetter - 'a'] == 1)
                vowelCount++;
        } else {
            consonantCount++;
        }

        while (consonantCount > k) {
            char startLetter = word[start];
            if (isVowel(startLetter)) {
                vowelFreq[startLetter - 'a']--;
                if (vowelFreq[startLetter - 'a'] == 0) {
                    vowelCount--;
                }
            } else {
                consonantCount--;
            }
            start++;
        }

        while (start < len && vowelCount == 5 &&
                consonantCount == k) {
            numValidSubstrings += nextConsonant[end] - end;
            char startLetter = word[start];
            if (isVowel(startLetter)) {
                vowelFreq[startLetter - 'a']--;
                if (vowelFreq[startLetter - 'a'] == 0) {
                    vowelCount--;
                }
            } else {
                consonantCount--;
            }

            start++;
        }
        end++;
    }

    return numValidSubstrings;
}
