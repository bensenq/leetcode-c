//ref: https://leetcode.com/problems/wildcard-matching/solutions/17810/linear-runtime-and-constant-space-solution/
//The basic idea is to have one pointer for the string and one pointer for the pattern. This algorithm iterates at most length(string) + length(pattern) times, for each iteration, at least one pointer advance one step.

bool isMatch(char* s, char* p) {
        const char* star=NULL;
        const char* match;
        while (*s) {
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p == '?') || (*p == *s)) {
                s++;
                p++; 
            } 

            // * found in pattern, track index of *, only advancing pattern pointer 
            else if (*p == '*') {
                star = p++; 
                match = s;
            } 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing matching string and reset pattern to * next
            else if (star) {
                p = star + 1;
                match++; 
                s = match;
            } 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            else return false;
        }

       //check for remaining characters in pattern
        while (*p == '*') p++;

        return !*p;      
}