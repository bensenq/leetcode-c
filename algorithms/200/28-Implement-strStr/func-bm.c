//ref: https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
# define NO_OF_CHARS 26 //only lower case letters
 
// The preprocessing function for Boyer Moore's
// bad character heuristic
void badCharHeuristic(char* str, int size,
                        int badchar[26])
{
    int i;
 
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;
 
    // Fill the actual value of last occurrence
    // of a character
    for (i = 0; i < size; i++)
        badchar[(int) str[i] - 'a'] = i;
}

/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
int strStr(char * haystack, char * needle){
    int m = strlen(needle);
    int n = strlen(haystack);
 
    int badchar[NO_OF_CHARS];
 
    /* Fill the bad character array by calling
    the preprocessing function badCharHeuristic()
    for given pattern */
    badCharHeuristic(needle, m, badchar);
 
    int s = 0; // s is shift of the pattern with
                // respect to text
    while(s <= (n - m))
    {
        int j = m - 1;
 
        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while(j >= 0 && needle[j] == haystack[s + j])
            j--;
 
        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0)
        {
            return s;
        }
 
        else
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            if (j - badchar[haystack[s + j] - 'a'] > 0)
                s += j - badchar[haystack[s + j] - 'a'];
            else
                s++;
    }
    return -1;    
}