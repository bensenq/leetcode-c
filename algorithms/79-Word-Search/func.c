//backtracking

#include <stdbool.h>

bool existBackTracking(char** board, int m, int n, int x, int y, char * word, int pos){
    int ret;
    if (word[pos] == 0)
        return true;
    
    //check up
    if (x > 0 && board[x-1][y] == word[pos]) {
        board[x-1][y] -= 64;
        ret = existBackTracking(board, m, n, x-1, y, word, pos+1);
        board[x-1][y] += 64;
        if (ret) return true;
    }

    //check right
    if (y < n-1 && board[x][y+1] == word[pos]) {
        board[x][y+1] -= 64;
        ret = existBackTracking(board, m, n, x, y+1, word, pos+1);
        board[x][y+1] += 64;
        if (ret) return true;
    }

    //check down
    if (x < m-1 && board[x+1][y] == word[pos]) {
        board[x+1][y] -= 64;
        ret = existBackTracking(board, m, n, x+1, y, word, pos+1);
        board[x+1][y] += 64;
        if (ret) return true;
    }
    //check left
    if (y > 0 && board[x][y-1] == word[pos]) {
        board[x][y-1] -= 64;
        ret = existBackTracking(board, m, n, x, y-1, word, pos+1);
        board[x][y-1] += 64;
        if (ret) return true;
    }

    return false;
}

bool exist(char** board, int boardSize, int *boardColSize, char * word){
    int m = boardSize;
    int n = boardColSize[0];
    int ret;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                board[i][j] -= 64;
                ret = existBackTracking(board, m, n, i, j, word, 1);
                board[i][j] += 64;
                if (ret == true)
                    return true;
            }
        }
    }
    return false;
}