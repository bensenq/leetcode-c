/* just calculate the sequence */
char * convert(char * s, int numRows){
    int center = (numRows == 1) ? 0 : (numRows - 2);
    int group = (numRows == 1) ? 1 : (numRows + center);
    int i, j, k;
    int len = strlen(s);
    char *result = malloc(len + 1);
    if (numRows == 1) { //only have one line
        memcpy(result, s, len);
        result[len] = 0;
        return result;
    }

    j = 0;
    // fisrt row
    i = 0;
    while (i < len) {
        result[j] = s[i];
        i = i + group;
        j++;
    }

    // for middle rows
    for (k = 1; k < numRows - 1; k++) {
        i = k;
        while (i < len) {
            result[j] = s[i];
            j++;
            if (i + 2*(numRows-1-i%group) < len) {
                result[j] = s[i + 2*(numRows-1-i%group)];
                j++;
                i = i + group;
            } else {
                break;
            }
        }
    }

    // last row
    i = numRows - 1;
    while (i < len) {
        result[j] = s[i];
        i = i + group;
        j++;
    }
    result[len] = 0;
    return result;
}

void main() {
    convert("PAYPALISHIRING", 3);
    convert("PAYPALISHIRING", 4);
}