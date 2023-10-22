void explore(int i, int j, char** grid, int r, int c) {
    if(i-1 >= 0 && grid[i-1][j] == '1') {    //up
        grid[i-1][j] = '2'; //mark explored
        explore(i-1, j, grid, r, c);
    }
    if(i+1 < r && grid[i+1][j] == '1') {    //down
        grid[i+1][j] = '2'; //mark explored
        explore(i+1, j, grid, r, c);
    }
    if(j-1 >= 0 && grid[i][j-1] == '1') {    //left
        grid[i][j-1] = '2'; //mark explored
        explore(i, j-1, grid, r, c);
    }
    if(j+1 < c && grid[i][j+1] == '1') {    //down
        grid[i][j+1] = '2'; //mark explored
        explore(i, j+1, grid, r, c);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int i, j;
    int r = gridSize;
    int c = gridColSize[0];
    int count = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (grid[i][j] == '1') {    //find unexplored land
                count++;
                grid[i][j] = '2'; //mark explored
                explore(i, j, grid, r, c);
            }
        }
    }
    return count;
}