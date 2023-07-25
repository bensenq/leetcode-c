#include <stdbool.h>
#include <string.h>

bool isMatch(char * s, char * p){
    if (*p == 0 && *s == 0)
        return true;
    if (*p == 0 && *s != 0)
        return false;

    if (*s !=0 && (*s == *p || *p == '.')) {
        if (strlen(p) >= 2 && p[1] == '*') 
            return isMatch(s+1, p) || isMatch(s, p+2);
        else
            return isMatch(s+1, p+1);
    } else if (strlen(p) >= 2 && p[1] == '*') {
        return isMatch(s, p+2);
    } else return false;
}

int main() {
    return isMatch("aaa", "a*a");
}