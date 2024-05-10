char * convert(char * s, int numRows){
    int group = (numRows == 1) ? 1 : (numRows*2-2);
    int center = (numRows == 1) ? 0 : numRows - 2;
    int column = strlen(s) / group * (center+1) + (numRows-1);
    char matrix[column][numRows];
    char *result;
    int i, j, k, c;
    
    if (numRows == 1) 
        return s;
    for (i = 0; i < column; i++) {
        memset(matrix[i], 0, numRows);
    }

    /* paint zigzag */
    i = 0; j = 0; c = 0;
    while(s[i] != 0) {
        if (j == 2*numRows-2) {
            c++;
            j = 0;
        }

        if (j < numRows) {
            matrix[c][j] = s[i];
        } else if (j >= numRows && j < 2*numRows - 2) {
            c++;
            matrix[c][2*numRows-2-j] = s[i];
        }
        j++;
        i++;
    }
    result = malloc(i+1);
    result[i] = 0;
    k = 0;
    /* collect string */
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < column; j++) {
            //printf("%c", matrix[j][i] == 0 ? ' ': matrix[j][i]);
            if(matrix[j][i] != 0) {
                result[k] = matrix[j][i];
                k++;
            }
        }
        printf("\n");
    }
    return result;
}

void main() {
    convert("PAHNAPLSIIGYIR", 3);
}