void markSurrender(int i, int j, char** matrix, int r, int c) {
    if (i-1 > 0 && matrix[i-1][j] == 'O') {     //up
        matrix[i-1][j] = '1';
        markSurrender(i-1, j, matrix, r, c);
    }
    if (i+1 < r-1 && matrix[i+1][j] == 'O') {   //down
        matrix[i+1][j] = '1';
        markSurrender(i+1, j, matrix, r, c);
    }
    if (j-1 > 0 && matrix[i][j-1] == 'O') {     //left
        matrix[i][j-1] = '1';
        markSurrender(i, j-1, matrix, r, c);        
    }
    if (j+1 < c-1 && matrix[i][j+1] == 'O') {   //right
        matrix[i][j+1] = '1';
        markSurrender(i, j+1, matrix, r, c);        
    }
}

void solve(char** board, int boardSize, int* boardColSize){
    int r = boardSize;
    int c = boardColSize[0];
    int i, j;
    for (j = 0; j < c; j++) {   
        if (board[0][j] == 'O') {   //top border
            board[0][j] = '1';  
            markSurrender(0, j, board, r, c);
        }

        if (board[r-1][j] == 'O') { //bottom border
            board[r-1][j] = '1';
            markSurrender(r-1, j, board, r, c);
        }
    }

    for (i = 1; i < r-1; i++) {
        if (board[i][0] == 'O') {   //left border
            board[i][0] = '1';
            markSurrender(i, 0, board, r, c);
        }

        if (board[i][c-1] == 'O') { //right border
            board[i][c-1] = '1';
            markSurrender(i, c-1, board, r, c);
        }        
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (board[i][j] == '1') board[i][j] = 'O';
            else if(board[i][j] == 'O') board[i][j] = 'X';
        }
    }
}