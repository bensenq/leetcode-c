#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

//ref:https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/

//1. Use two pointers: start and end to represent a window.
//2. Move end to find a valid window.
//3. When a valid window is found, move start to find a smaller window.

char* minWindow(char* s, char* t) {
    int sl, tl;
    int map[128];
    memset(map, 0, 128 * sizeof(int));

    sl = strlen(s);
    tl = strlen(t);

    for (int i = 0; i < tl; i++) {
        map[t[i]]++;
    }
    int counter = tl;
    int left = 0, right = 0, distance = INT_MAX, start = 0;
    while(right < sl) {
        map[s[right]]--;
        if(map[s[right]] >= 0) {
            counter--;
        }
        right++;

        while(counter == 0) {
            if (right - left < distance) {
                start = left;
                distance = right - left;
            }
            map[s[left]]++;
            if (map[s[left]] > 0)
                counter++;
            left++;
        }
    }

    if (distance != INT_MAX)
        return strndup(s+start, distance);
    
    return "";
}

int main() {
    char *s = minWindow("ADOBECODEBANC","ABC");
    return 0;
}