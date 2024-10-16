bool accessed(unsigned long long *bitmap, int n, int x, int y){
    int index = (y * n + x) / 64;
    int offset = (y * n + x) % 64;
    return bitmap[index] & (0x1ULL << offset);
}
void setAccessed(unsigned long long *bitmap, int n, int x, int y){
    int index = (y * n + x) / 64;
    int offset = (y * n + x) % 64;
    bitmap[index] = bitmap[index] | (0x1ULL << offset);
}

struct point {
    int x;
    int y;
    struct point * next;
};

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int m = mazeSize, n = mazeColSize[0];
    unsigned long long *bitmap = calloc(m*n/64+1, 8);
    int y = entrance[0], x = entrance[1];
    int count = 0;
    int cur_size = 1, next_size = 0;
    struct point *head = malloc(sizeof(struct point));
    struct point *tail = head, *tmp = head;
    head->x = x;
    head->y = y;
    head->next = 0;
    tmp = head;
    setAccessed(bitmap, n, x, y);
    while(cur_size > 0 || next_size > 0) {
        if (cur_size == 0) {
            cur_size = next_size;
            next_size = 0;
            count++;
        }
        x = head->x;
        y = head->y;
        
        /* left */
        if (x - 1 >= 0 && maze[y][x-1] == '.' && !accessed(bitmap, n, x - 1, y)) {
            if (x - 1 == 0 || y == m - 1 || y == 0) {
                count++;
                break;
            } else {
                next_size++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = x - 1;
                tail->y = y;
                tail->next = 0; 
                setAccessed(bitmap, n, x-1, y);
            }
        }

        /* right */
        if (x + 1 < n  && maze[y][x+1] == '.' && !accessed(bitmap, n, x + 1, y)) {
            if (x + 1 == n - 1 || y == m - 1 || y == 0) {
                count++;
                break;
            } else {
                next_size++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = x + 1;
                tail->y = y;
                tail->next = 0; 
                setAccessed(bitmap, n, x+1, y);
            }
        }

        /* up */
        if (y - 1 >= 0 && maze[y-1][x] == '.' && !accessed(bitmap, n, x, y - 1)) {
            if (x == 0 || x == n - 1 || y - 1 == 0) {
                count++;
                break;
            } else {
                next_size++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = x;
                tail->y = y - 1;
                tail->next = 0; 
                setAccessed(bitmap, n, x, y-1);
            }
        }

        /* down */
        if (y + 1 < m && maze[y+1][x] == '.' && !accessed(bitmap, n, x, y + 1)) {
            if (x == 0 || x == n - 1 || y + 1 == m - 1) {
                count++;
                break;
            } else {
                next_size++;
                tail->next = malloc(sizeof(struct point));
                tail = tail->next;
                tail->x = x;
                tail->y = y + 1;
                tail->next = 0;
                setAccessed(bitmap, n, x, y+1);
            }
        }

        head = head->next;
        cur_size--;
    }

    /* clean up */
    head = tmp;
    while(head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(bitmap);

    if (cur_size == 0 && next_size == 0)
        return -1;
    return count;
}