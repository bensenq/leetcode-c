struct point {
    int x, y;
    struct point * next;
};

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int rotten, new_rotten = 0, fresh = 0;
    int minute = 0;
    struct point guard;
    struct point *head = &guard, *tail = head, *tmp = head;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                fresh++;
            } else if(grid[i][j] == 2) {
                new_rotten++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = j;
                tail->y = i;
                tail->next = 0;
            }
        }
    }
    head = head->next;
    while(1) {
        if (fresh == 0 || new_rotten == 0)break;
        else {
            rotten = new_rotten;
            new_rotten = 0;
            minute++;
        }
        while(rotten > 0) {
            int x = head->x;
            int y = head->y;
            if (x-1 >= 0 && grid[y][x-1] == 1) {
                grid[y][x-1] = 2;
                new_rotten++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = x-1;
                tail->y = y;
                tail->next = 0;
                fresh--;
            }

            if (x+1 < n && grid[y][x+1] == 1) {
                grid[y][x+1] = 2;
                new_rotten++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = x+1;
                tail->y = y;
                tail->next = 0;
                fresh--;
            }

            if (y-1 >= 0 && grid[y-1][x] == 1) {
                grid[y-1][x] = 2;
                new_rotten++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = x;
                tail->y = y-1;
                tail->next = 0;
                fresh--;
            }

            if (y+1 < m && grid[y+1][x] == 1) {
                grid[y+1][x] = 2;
                new_rotten++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = x;
                tail->y = y+1;
                tail->next = 0;
                fresh--;
            }
            rotten--;
            head = head->next;
        }
    }

    /* cleanup */
    head = tmp->next;
    while(head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    if (fresh == 0)
        return minute;
    else
        return -1;
}