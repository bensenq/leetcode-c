// hashtable for exist: 0 not exist.

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    char hash_r[9][9] = {0}; //row
    char hash_c[9][9] = {0}; //column
    char hash_b[9][9] = {0}; //block
    int i, j, k;
    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int index = board[i][j] - '1';
                int x = (i / 3) * 3 + (j / 3);
                if (hash_r[i][index] == 0 
                    && hash_c[j][index] == 0
                    && hash_b[x][index] == 0) {
                    hash_r[i][index] = 1;
                    hash_c[j][index] = 1;
                    hash_b[x][index] = 1;
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}