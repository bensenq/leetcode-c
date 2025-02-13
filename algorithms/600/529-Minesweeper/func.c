#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_M 50
#define MAX_N 50


// Recursive function to reveal blank squares on the original board
void revealBlank(char** board, int m, int n, int x, int y) {
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Check if the cell is out of bounds or already revealed
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'E') {
        return;
    }

    // count mines
    int minesCount = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'M') {
            minesCount++;
            }
    }

    // If there are no mines around, reveal as blank and recursively reveal neighbors
    if (minesCount == 0) {
        board[x][y] = 'B';
        for (int i = 0; i < 8; i++) {
            revealBlank(board, m, n, x + dx[i], y + dy[i]);
        }
    } else {
        // If there are mines around, reveal the count
        board[x][y] = '0' + minesCount;
    }
}

char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
    int m = boardSize;
    int n = boardColSize[0];
    int clickr = click[0];
    int clickc = click[1];

    // If the clicked cell is a mine, reveal it as 'X'
    if (board[clickr][clickc] == 'M') {
        board[clickr][clickc] = 'X';
    } else {
        // If the clicked cell is an empty square, reveal it and its neighbors
        revealBlank(board, m, n, clickr, clickc);
    }

    // Prepare the return values
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return board;
}

int main() {
    // Allocate memory for the board
    char** boardInput = (char**)malloc(4 * sizeof(char*));
    for (int i = 0; i < 4; i++) {
        boardInput[i] = (char*)malloc(5 * sizeof(char));
    }

    // Initialize the board
    strcpy(boardInput[0], "EEEEE");
    strcpy(boardInput[1], "EEMEE");
    strcpy(boardInput[2], "EEEEE");
    strcpy(boardInput[3], "EEEEE");

    int m = 4;
    int n = 5;
    int click[] = {3, 0};

    int returnSize;
    int* returnColumnSizes;

    updateBoard(boardInput, m, &n, click, 2, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%c ", boardInput[i][j]);
        }
        printf("\n");
        free(boardInput[i]);
    }
    free(boardInput);
    free(returnColumnSizes);

    return 0;
}