// hashtable solution

// Function to count the frequency of each letter in a string
void countLetters(const char* str, int* count) {
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) { // If the character is a letter
            count[tolower(str[i]) - 'a']++; // Convert to lowercase and count
        }
    }
}

// Function to check if a word is a completing word
int isCompletingWord(int* licenseCount, int* wordCount) {
    for (int i = 0; i < 26; i++) {
        if (licenseCount[i] > wordCount[i]) {
            return 0; // If the frequency of any letter in the word is less than in licensePlate, it is not a completing word
        }
    }
    return 1; // Otherwise, it is a completing word
}

char* shortestCompletingWord(const char* licensePlate, char** words, int wordsSize) {
    int licenseCount[26] = {0};
    countLetters(licensePlate, licenseCount); // Count the frequency of letters in licensePlate

    char* result = NULL;
    int minLen = INT_MAX;

    for (int i = 0; i < wordsSize; i++) {
        int wordCount[26] = {0};
        countLetters(words[i], wordCount); // Count the frequency of letters in the current word

        if (isCompletingWord(licenseCount, wordCount)) { // If the word is a completing word
            int len = strlen(words[i]);
            if (len < minLen) { // If the length of the current word is less than the known minimum length
                minLen = len;
                result = words[i]; // Update the result
            }
        }
    }

    return result;
}