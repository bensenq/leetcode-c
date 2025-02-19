int titleToNumber(char* columnTitle) {
    int columnNumber = 0;
    unsigned long long weight = 1;
    int length = strlen(columnTitle);

    for (int i = length - 1; i >= 0; i--) {
        int currentNumber = columnTitle[i] - 'A' + 1;
        columnNumber += currentNumber * weight;
        weight *= 26;
    }

    return columnNumber;
}