int countBattleships(char** board, int boardRowSize, int boardColSize) {
        int count = 0;
        int i, j;
        for (i = 0; i < boardRowSize; i++) {
                for (j = 0; j < boardColSize; j++) {
                        if (board[i][j] == 'X') {
                                count++;
                                int k = j + 1;
                                int d = 0;
                                while (k < boardColSize && board[i][k] == 'X') {
                                        d = 1;
                                        board[i][k] = 0;
                                        k++;
                                }
                                if (d != 1) {
                                        k = i + 1;
                                        while (k < boardRowSize && board[k][j] == 'X') {
                                                board[k][j] = 0;
                                                k++;
                                        }
                                }
                        }
                        if (board[i][j] == 0)
                            j++;
                }
        }
        return count;
}
