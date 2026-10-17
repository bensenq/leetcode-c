// Intuitive simple 2-pass check, first pass we assume all stars are open parenthesis, second pass we assume all stars are close parenthesis

bool checkValidString(char* s) {

    int numOpen = 0, numClose = 0, numStar = 0;
    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];
        switch (c) {
            case '(':
                numOpen++;break;
            case ')':
                numClose++;break;
            case '*':
                numStar++;break;
        }
        if (numClose > numOpen + numStar) {
            return false;
        }
    }

    numOpen = 0, numClose = 0, numStar = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        char c = s[i];
        switch (c) {
            case '(':
                numOpen++;break;
            case ')':
                numClose++;break;
            case '*':
                numStar++;break;
        }
        if (numOpen > numClose + numStar) {
            return false;
        }
    }

    return true;
}
