char* removeOccurrences(char* s, char* part) {
    // Get the length of the substring 'part' to be removed
    int partLen = strlen(part);

    // Get the initial length of the string 's'
    int sLen = strlen(s);

    // Use strstr to find the first occurrence of 'part' in 's'
    char* pos = strstr(s, part);
    while (pos != NULL) {
        // Calculate the offset of 'pos' from the beginning of 's'
        int offset = pos - s;

        // Remove 'part' from 's' by moving the substring after 'part' forward
        // The substring after 'part' is moved up by 'partLen' characters
        memmove(s + offset, s + offset + partLen, sLen - offset - partLen + 1);

        // Update the length of the string 's'
        sLen -= partLen;

        // Continue searching for the next occurrence of 'part'
        pos = strstr(s, part);
    }

    return s;
}