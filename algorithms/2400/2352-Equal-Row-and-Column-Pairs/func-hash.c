/* position_weighted_hash: prime = 7 */

/* unsigned int position_weighted_hash(const void* data, size_t size, size_t prime) {
    unsigned char* bytes = (unsigned char*)data;
    unsigned int hash = 0;
    for (size_t i = 0; i < size; ++i) {
        hash += bytes[i] * prime;
        prime *= prime;
    }
    return hash;
}*/

int equalPairs(int** grid, int gridSize, int* gridColSize) {
    int count = 0, i, j, k;
    unsigned int *hash_row = calloc(sizeof(unsigned int), gridSize);
    unsigned int *hash_col = calloc(sizeof(unsigned int), gridSize);
    for (i = 0; i < gridSize; i++) {
        unsigned int hash = 0;
        unsigned int prime = 7;
        for (j = 0; j < gridSize; j++) {
            hash += grid[i][j] * prime;
            prime *= prime;
        }
        hash_row[i] = hash;
    }

    for (i = 0; i < gridSize; i++) {
        unsigned int hash = 0;
        unsigned int prime = 7;
        for (j = 0; j < gridSize; j++) {
            hash += grid[j][i] * prime;
            prime *= prime;
        }
        hash_col[i] = hash;
    }

    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < gridSize; j++) {
            if (hash_row[i] == hash_col[j]) {
                /* checking possible hash collision */
                for (k = 0; k < gridSize; k++) {
                    if (grid[i][k] != grid[k][j])break;
                }
                if (k == gridSize) count++;
            }
        }
    }
    free(hash_row);
    free(hash_col);
    return count;
}