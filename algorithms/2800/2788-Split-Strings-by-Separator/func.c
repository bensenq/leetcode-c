/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_RESULTS 1000  // Define the maximum number of substrings

char** splitWordsBySeparator(char** words, int wordsSize, char separator, int* returnSize) {
    // Initialize the result array with a fixed size
    char** result = (char**)malloc(MAX_RESULTS * sizeof(char*));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    *returnSize = 0;  // Initialize the return size

    // Iterate through each string in the input array
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int wordLen = strlen(word);
        int start = 0;

        // Iterate through the current string to find separators
        for (int j = 0; j <= wordLen; j++) {
            // Check if we've reached the end of the string or found a separator
            if (j == wordLen || word[j] == separator) {
                // Calculate the length of the substring
                int len = j - start;

                // If the substring is not empty
                if (len > 0) {
                    // Check if the result array has space
                    if (*returnSize >= MAX_RESULTS) {
                        fprintf(stderr, "Exceeded maximum number of results\n");
                        exit(1);
                    }

                    // Allocate memory for the substring (including null terminator)
                    char* subStr = (char*)malloc((len + 1) * sizeof(char));
                    if (subStr == NULL) {
                        fprintf(stderr, "Memory allocation failed\n");
                        exit(1);
                    }

                    // Copy the substring
                    strncpy(subStr, word + start, len);
                    subStr[len] = '\0';

                    // Add the substring to the result array
                    result[*returnSize] = subStr;
                    (*returnSize)++;
                }

                // Update the start position to the next character after the separator
                start = j + 1;
            }
        }
    }

    return result;
}