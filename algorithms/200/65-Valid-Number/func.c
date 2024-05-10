#include <stdbool.h>
#include <string.h>

bool isInteger(char *s){
    int i = 0;
    int len = 0;
    while(s[i] != 0) {
        if (s[i] == '+' || s[i] == '-') {
            if (i != 0) return false;
        } else if (s[i] < '0' || s[i] > '9') return false;
        else len++;
        i++;
    }
    if (len == 0) return false;
    return true;
}

bool isDecimalInteger(char *s) {
    int i = 0;
    int len = 0;
    int point_times = 0;
    while(s[i] != 0) {
        if ((s[i] == '+' || s[i] == '-')) {
            if(i != 0) return false;
        } else if (s[i] == '.') {
            point_times++;
            if (point_times > 1) return false;
        } else if (s[i] < '0' || s[i] > '9') return false;
        else len++;
        i++;
    }
    if (len == 0) return false;
    return true;
}

bool isNumber(char* s) {
    int i = 0;
    int e_position = -1;
    int dot_times = 0;
    while (s[i] != 0) {
        if (s[i] == 'e' || s[i] == 'E') {
            if (e_position == -1)
                e_position = i;
        }
        i++;
    }
    if (e_position != -1) {
        char *s_left = strndup(s, e_position);
        char *s_right = strdup(s + e_position + 1);
        return (isDecimalInteger(s_left)) && isInteger(s_right);
    }
    else
        return isDecimalInteger(s);
}

int main() {
    return isNumber("-1.");
}