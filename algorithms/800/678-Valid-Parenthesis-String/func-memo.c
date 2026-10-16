// Editorial Approach1: Top-Down Dynamic Programming - Memoization

int isValidString(int index, int openCount, char *str, int **memo) {
    // If reached end of the string, check if all brackets are balanced
    if(index == strlen(str)) {
        return (openCount == 0);
    }
    // If already computed, return memoized result
    if (memo[index][openCount] != -1) {
        return memo[index][openCount];
    }
    bool isValid = false;
    // If encountering '*', try all possibilities
    if (str[index] == '*') {
        isValid |= isValidString(index + 1, openCount + 1, str, memo); // Treat '*' as '('
        if (openCount) {
            isValid |= isValidString(index + 1, openCount - 1, str, memo); // Treat '*' as ')'
        }
        isValid |= isValidString(index + 1, openCount, str, memo); // Treat '*' as empty
    } else {
        // Handle '(' and ')'
        if (str[index] == '(') {
            isValid = isValidString(index + 1, openCount + 1, str, memo); // Increment count for '('
        } else if (openCount) {
            isValid = isValidString(index + 1, openCount - 1, str, memo); // Decrement count for ')'
        }
    }

    // Memoize and return the result
    return memo[index][openCount] = isValid;
}

bool checkValidString(char* s) {
    int n = strlen(s);
    int **memo = malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++) {
        memo[i] = malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++)
            memo[i][j] = -1;
    }

    bool result = isValidString(0, 0, s, memo);

    //cleanup
    for(int i = 0; i < n; i++)
        free(memo[i]);
    free(memo);
    return result;
}
