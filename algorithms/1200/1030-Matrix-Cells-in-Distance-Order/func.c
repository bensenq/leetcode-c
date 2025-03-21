// Helper function: Expand a single point and return whether the expansion was successful
bool expandPoint(int** result, int* index, int r, int c, int row, int col) {
    if (r >= 0 && r < row && c >= 0 && c < col) {  // Check if the point is within the matrix bounds
        result[*index][0] = r;
        result[*index][1] = c;
        (*index)++;
        return true;  // Expansion successful
    }
    return false;  // Expansion failed
}

// Main function
int** allCellsDistOrder(int row, int col, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    int size = row * col;
    int** result = (int**)malloc(size * sizeof(int*));
    *returnColumnSizes = (int*)malloc(size * sizeof(int));
    *returnSize = size;
    int index = 0;

    // Initialize the result array
    for (int i = 0; i < size; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }

    // Manually build the 0th layer (the center point definitely exists)
    result[index][0] = rCenter;
    result[index][1] = cCenter;
    index++;

    int start = index;

    // Manually build the 1st layer
    bool hasUp = expandPoint(result, &index, rCenter - 1, cCenter, row, col);
    bool hasDown = expandPoint(result, &index, rCenter + 1, cCenter, row, col);
    int expandLeft = expandPoint(result, &index, rCenter, cCenter - 1, row, col);
    int expandRight = expandPoint(result, &index, rCenter, cCenter + 1, row, col);

    // Start expanding from the 2nd layer
    int currentDepth = 2;
    while (index < size) {
        bool newHasUp = false, newHasDown = false;
        int newExpandLeft = 0, newExpandRight = 0;

        // Vertical expansion
        if (hasUp) {
            newHasUp = expandPoint(result, &index, rCenter - currentDepth, cCenter, row, col);
            start++;
        }

        if (hasDown) {
            newHasDown = expandPoint(result, &index, rCenter + currentDepth, cCenter, row, col);
            start++;
        }

        // Horizontal expansion: left
        if (hasUp) {
            newExpandLeft += expandPoint(result, &index, rCenter - currentDepth + 1, cCenter - 1, row, col);
        }
        if (hasDown) {
            newExpandLeft += expandPoint(result, &index, rCenter + currentDepth - 1, cCenter - 1, row, col);
        }
        for (int i = 0; i < expandLeft; i++) {
            newExpandLeft += expandPoint(result, &index, result[start + i][0], result[start + i][1] - 1, row, col);
        }
        start += expandLeft;

        // Horizontal expansion: right
        if (hasUp) {
            newExpandRight += expandPoint(result, &index, rCenter - currentDepth + 1, cCenter + 1, row, col);
        }
        if (hasDown) {
            newExpandRight += expandPoint(result, &index, rCenter + currentDepth - 1, cCenter + 1, row, col);
        }
        for (int i = 0; i < expandRight; i++) {
            newExpandRight += expandPoint(result, &index, result[start + i][0], result[start + i][1] + 1, row, col);
        }

        start += expandRight;

        // Update the flags
        hasUp = newHasUp;
        hasDown = newHasDown;
        expandLeft = newExpandLeft;
        expandRight = newExpandRight;

        currentDepth++;
    }

    return result;
}