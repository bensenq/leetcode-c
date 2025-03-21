int minimumRecolors(char* blocks, int k) {
    int n = strlen(blocks);
    int max_black = 0;
    int current_black = 0;

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        if (blocks[i] == 'B') {
            current_black++;
        }
    }
    max_black = current_black;

    // Slide the window across the string
    for (int i = k; i < n; i++) {
        // If we find a window with k black blocks, return 0
        if (max_black == k) {
            return 0;
        }
        // Remove the leftmost element of the previous window
        if (blocks[i - k] == 'B') {
            current_black--;
        }
        // Add the new rightmost element to the current window
        if (blocks[i] == 'B') {
            current_black++;
        }
        // Update the maximum number of black blocks found
        if (current_black > max_black) {
            max_black = current_black;
        }
    }

    // The minimum number of operations is k minus the maximum number of black blocks
    return k - max_black;    
}