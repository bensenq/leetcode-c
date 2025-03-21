void dfs(int index, char* visited, int **isConnected, int size) {
    visited[index] = 1;
    for (int i = 0; i < size; i++) {
        if (i != index && isConnected[index][i] == 1 && visited[i] == 0) {
            dfs(i, visited, isConnected, size);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    char *visited = calloc(1, isConnectedSize);
    int count = 0;
    for (int i = 0; i < isConnectedSize; i++) {
        if (visited[i] == 0) {
            count++;
            dfs(i, visited, isConnected, isConnectedSize);
        }
    }
    free(visited);
    return count;
}