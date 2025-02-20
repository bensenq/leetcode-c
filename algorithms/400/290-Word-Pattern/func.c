// Define a structure to record whether a word has been mapped
typedef struct {
    char* word;        // The word (used as the key)
    UT_hash_handle hh; // Uthash handle
} WordHash;

bool wordPattern(char* pattern, char* s) {
    char* wordMap[26] = {0}; // Array to record the word each character in pattern maps to
    WordHash* wordSet = NULL; // Hash table to record whether a word has been mapped

    char* token = strtok(s, " "); // Split the string s by spaces
    int i = 0; // Index to iterate through pattern

    while (token != NULL) {
        if (i >= strlen(pattern)) { // If there are no more characters in pattern but there are still words in s
            return false;
        }

        char c = pattern[i];
        int index = c - 'a'; // Calculate the index for the character

        // Check if the current character has not been mapped to any word
        if (wordMap[index] == NULL) {
            WordHash* entry;
            HASH_FIND(hh, wordSet, token, strlen(token), entry); // Check if the word has been mapped

            if (entry != NULL) { // If the word has already been mapped
                return false;
            }

            // Create a new mapping
            wordMap[index] = strdup(token); // Map the character to the word
            entry = (WordHash*)malloc(sizeof(WordHash));
            entry->word = strdup(token);
            HASH_ADD_STR(wordSet, word, entry); // Add the word to the hash table
        } else { // If the current character has been mapped
            if (strcmp(wordMap[index], token) != 0) { // Check if the mapping is consistent
                return false;
            }
        }

        token = strtok(NULL, " "); // Get the next word
        i++; // Move to the next character in pattern
    }

    // If there are remaining characters in pattern but no more words in s
    if (i < strlen(pattern)) {
        return false;
    }

    // Clean up allocated memory
    for (int j = 0; j < 26; j++) {
        if (wordMap[j] != NULL) {
            free(wordMap[j]);
        }
    }

    WordHash* current;
    WordHash* tmp;
    HASH_ITER(hh, wordSet, current, tmp) {
        HASH_DEL(wordSet, current);
        free(current->word);
        free(current);
    }

    return true; // Return success
}