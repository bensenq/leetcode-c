int solveSodukuWithMap(char** board, char hash_r[9][9], char hash_c[9][9], char hash_b[9][9]) {
    int i, j, k, x;
    int ret;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == '.') {   //found fisrt unfilled letter
                int x = (i / 3) * 3 + (j / 3);
                for (k = 0; k < 9; k++) {
                    int exist = hash_r[i][k] || hash_c[j][k] || hash_b[x][k];
                    if (exist == 0) {
                        board[i][j] = k + '1';
                        hash_r[i][k] =  hash_c[j][k] = hash_b[x][k] = 1;
                        if (solveSodukuWithMap(board, hash_r, hash_c, hash_b) == 0) {
                            //failed: restore
                            hash_r[i][k] =  hash_c[j][k] = hash_b[x][k] = 0;
                            board[i][j] = '.';
                        } else {
                            //solved
                            ret = 1;
                            goto out;
                        }
                    } 
                }
                if (k == 9) {
                    ret = 0; //not valid
                    goto out;
                }
            }
        }
    }
out:
    return ret;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
    char hash_r[9][9] = {0}; //row
    char hash_c[9][9] = {0}; //column
    char hash_b[9][9] = {0}; //block
    int i, j, k;

    // build initial existence map.
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int index = board[i][j] - '1';
                int x = (i / 3) * 3 + (j / 3);
                hash_r[i][index] = 1;
                hash_c[j][index] = 1;
                hash_b[x][index] = 1;
            }
        }
    }
    solveSodukuWithMap(board, hash_r, hash_c, hash_b);
}

int main() {

    char row0[] = {'5','3','.','.','7','.','.','.','.'};
    char row1[] = {'6','.','.','1','9','5','.','.','.'};
    char row2[] = {'.','9','8','.','.','.','.','6','.'};
    char row3[] = {'8','.','.','.','6','.','.','.','3'};
    char row4[] = {'4','.','.','8','.','3','.','.','1'};
    char row5[] = {'7','.','.','.','2','.','.','.','6'};
    char row6[] = {'.','6','.','.','.','.','2','8','.'};
    char row7[] = {'.','.','.','4','1','9','.','.','5'};
    char row8[] = {'.','.','.','.','8','.','.','7','9'};
    char *board[9] = {row0, row1, row2, row3, row4, row5, row6, row7, row8};
    solveSudoku(board, 9, 0);
    return 0;
}