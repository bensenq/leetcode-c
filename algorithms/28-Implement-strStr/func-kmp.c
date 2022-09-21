//ref: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching// well explained.

#include <string.h>

void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int strStr(char * haystack, char * needle){
    int M = strlen(needle);
    int N = strlen(haystack);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(needle, M, lps);
 
    int i = 0; // index for haystack[]
    int j = 0; // index for needle[]
    while ((N - i) >= (M - j)) {
        if (needle[j] == haystack[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            return (i - j);
        }
 
        // mismatch after j matches
        else if (i < N && needle[j] != haystack[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return -1;
}