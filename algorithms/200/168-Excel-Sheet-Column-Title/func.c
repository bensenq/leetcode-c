char* convertToTitle(int columnNumber) {
    char *result = malloc(8);
    int index = 0;

    while (columnNumber > 0) {
        columnNumber--;
        char currentChar = 'A' + (columnNumber % 26);
        result[index++] = currentChar;
        columnNumber /= 26;
    }

    result[index] = '\0';

    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    return result;
}