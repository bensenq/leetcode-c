bool isPathCrossing(char* path) {
    int len = strlen(path);
    bool result = false;
    int row = 2 * len + 1;
    int x = len, y = len;
    char **visited = calloc(sizeof(char*), row);
    visited[len] = calloc(sizeof(char), row);
    visited[len][len] = 1;
    int i = 0;
    while(i < len) {
        switch(path[i]) {
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
        }
        //check if visited
        if (visited[x] != 0) {
            if(visited[x][y] == 1) {
                result = true;
                break;
            } else visited[x][y] = 1;
        } else {
            visited[x] = calloc(sizeof(char*), row);
            visited[x][y] = 1;
        }
        i++;
    }
    for (i = 0; i < row; i++) {
        if (visited[i] != 0) free(visited[i]);
    }
    free(visited);
    return result;
}