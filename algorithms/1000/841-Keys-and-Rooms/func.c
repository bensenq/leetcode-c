bool dfs(int index, int **rooms, int roomsSize, int* roomsColSize, char *visited, int *count) {
    visited[index] = 1;
    *count += 1;
    if (*count == roomsSize) return true;
    for (int i = 0; i < roomsColSize[index]; i++) {
        if (visited[rooms[index][i]] == 0) {
            if(dfs(rooms[index][i], rooms, roomsSize, roomsColSize, visited, count))
                return true;
        }
    }
    return false;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    char *visited = calloc(1, roomsSize);
    int count = 0;
    bool ans = dfs(0, rooms, roomsSize, roomsColSize, visited, &count);
    free(visited);
    return ans;    
}