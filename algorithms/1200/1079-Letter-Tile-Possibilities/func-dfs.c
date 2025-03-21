// ref: https://leetcode.com/problems/letter-tile-possibilities/solutions/308284/concise-java-solution/

// Depth-first search function to calculate the number of tile possibilities
int dfs(int *arr) {
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        if (arr[i] == 0) continue;
        sum++;
        arr[i]--;
        sum += dfs(arr);
        arr[i]++;
    }
    return sum;
}

// Function to calculate the number of tile possibilities
int numTilePossibilities(char *tiles) {
    int count[26] = {0}; // Array to store the frequency of each character

    // Count the frequency of each character in the input string
    for (int i = 0; tiles[i] != '\0'; ++i) {
        count[tiles[i] - 'A']++;
    }

    // Call the DFS function to calculate the number of possibilities
    return dfs(count);
}