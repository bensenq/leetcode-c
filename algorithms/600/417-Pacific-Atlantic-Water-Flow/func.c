//BFS

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define PACIFIC 1
#define ATLANTIC 2

void markOceanFlow(int** heights, int **mask, int m, int n, int ocean) {
    int setSize, newsetSize = 0;
    int **set = malloc(sizeof(int*) * m * n);
    int **newset = malloc(sizeof(int*) * m * n);
    int **tmp;
    bool **visited = malloc(sizeof(bool*) * m);
    for (int i = 0; i < m; i++) {
        visited[i] = calloc(sizeof(bool), n);
    }
    int column, row;
    if (ocean == PACIFIC) {
        for (int j = 0; j < n; j++) {
            newset[newsetSize] = malloc(sizeof(int) * 2);
            newset[newsetSize][0] = 0;
            newset[newsetSize][1] = j;
            newsetSize++;
            visited[0][j] = true;
            mask[0][j] |= ocean;
        }
        for (int i = 1; i < m; i++) {
            newset[newsetSize] = malloc(sizeof(int) * 2);
            newset[newsetSize][0] = i;
            newset[newsetSize][1] = 0;
            newsetSize++;
            visited[i][0] = true;
            mask[i][0] |= ocean;
        }
    } else {
        for (int j = 0; j < n; j++) {
            newset[newsetSize] = malloc(sizeof(int) * 2);
            newset[newsetSize][0] = m - 1;
            newset[newsetSize][1] = j;
            newsetSize++;
            visited[m - 1][j] = true;
            mask[m - 1][j] |= ocean;
        }
        for (int i = 0; i < m - 1; i++) {
            newset[newsetSize] = malloc(sizeof(int) * 2);
            newset[newsetSize][0] = i;
            newset[newsetSize][1] = n - 1;
            newsetSize++;
            visited[i][n - 1] = true;
            mask[i][n - 1] |= ocean;
        }
    }

    do {
        tmp = set;
        set = newset;
        newset = tmp;
        setSize = newsetSize;
        newsetSize = 0;
        for (int i = 0; i < setSize; i++) {
            int x = set[i][0], y = set[i][1];
            free(set[i]);
            if(x > 0 && !visited[x-1][y] && heights[x-1][y] >= heights[x][y]) {
                visited[x-1][y] = true;
                newset[newsetSize] = malloc(sizeof(int) * 2);
                newset[newsetSize][0] = x - 1;
                newset[newsetSize][1] = y;
                mask[x-1][y] |= ocean;
                newsetSize++;
            }
            if(x < m - 1 && !visited[x+1][y] && heights[x+1][y] >= heights[x][y]) {
                visited[x+1][y] = true;
                newset[newsetSize] = malloc(sizeof(int) * 2);
                newset[newsetSize][0] = x + 1;
                newset[newsetSize][1] = y;
                mask[x+1][y] |= ocean;
                newsetSize++;
            }
            if(y > 0 && !visited[x][y-1] && heights[x][y-1] >= heights[x][y]) {
                visited[x][y-1] = true;
                newset[newsetSize] = malloc(sizeof(int) * 2);
                newset[newsetSize][0] = x;
                newset[newsetSize][1] = y - 1;
                mask[x][y-1] |= ocean;
                newsetSize++;
            }
            if(y < n - 1 && !visited[x][y+1] && heights[x][y+1] >= heights[x][y]) {
                visited[x][y+1] = true;
                newset[newsetSize] = malloc(sizeof(int) * 2);
                newset[newsetSize][0] = x;
                newset[newsetSize][1] = y + 1;
                mask[x][y+1] |= ocean;
                newsetSize++;
            }            
        }
    } while(newsetSize);
    free(set);
    free(newset);
    for (int i = 0; i < m; i++) {
        free(visited[i]);
    }
    free(visited);    
    return;
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {

    int m = heightsSize, n = heightsColSize[0];
    int size = 0;
    int **result = malloc(sizeof(int *) * m * n);
    int **mask = malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        mask[i] = calloc(sizeof(int), n);
    }

    markOceanFlow(heights, mask, m, n, PACIFIC);
    markOceanFlow(heights, mask, m, n, ATLANTIC);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mask[i][j] == (ATLANTIC | PACIFIC)) {
                result[size] = malloc(sizeof(int) * 2);
                result[size][0] = i;
                result[size][1] = j;
                size++;
            }
        }
    }    

    *returnColumnSizes = malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) (*returnColumnSizes)[i] = 2;
    *returnSize = size;
    result = realloc(result, sizeof(int*)*size);
    return result;
}
