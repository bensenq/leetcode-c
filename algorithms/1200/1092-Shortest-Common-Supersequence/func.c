// Editorial: Approach 4: Most Optimal - Space Optimized Dynamic Programming

char* shortestCommonSupersequence(char* str1, char* str2) {
    int str1Length = strlen(str1);
    int str2Length = strlen(str2);

    int **dp = malloc(sizeof(int*) * (str1Length + 1));
    for (int i = 0; i <= str1Length; i++) {
        dp[i] = malloc(sizeof(int*) * (str2Length + 1));
    }

    // Initialize the base cases
    // When str2 is empty, the supersequence is str1 itself
    // (length = row index)
    for (int row = 0; row <= str1Length; row++) {
        dp[row][0] = row;
    }
    // When str1 is empty, the supersequence is str2 itself
    // (length = col index)
    for (int col = 0; col <= str2Length; col++) {
        dp[0][col] = col;
    }

    // Fill the DP table
    for (int row = 1; row <= str1Length; row++) {
        for (int col = 1; col <= str2Length; col++) {
            if (str1[row - 1] == str2[col - 1]) {
                // If characters match,
                // inherit the length from the diagonal + 1
                dp[row][col] = dp[row - 1][col - 1] + 1;
            } else {
                // If characters do not match,
                // take the minimum length option + 1
                dp[row][col] = fmin(dp[row - 1][col], dp[row][col - 1]) + 1;
            }
        }
    }

    char *supersequence = malloc(dp[str1Length][str2Length] + 1);
    int i = 0;
    int row = str1Length, col = str2Length;

    while (row > 0 && col > 0) {
        if (str1[row - 1] == str2[col - 1]) {
            // If characters match, take it from diagonal
            supersequence[i++] = str1[row - 1];
            row--;
            col--;
        } else if (dp[row - 1][col] < dp[row][col - 1]) {
            // If str1’s character is part of the supersequence, move up
            supersequence[i++] = str1[row - 1];
            row--;
        } else {    // dp[row - 1][col] >= dp[row][col - 1]
            // If str2’s character is part of the supersequence, move left
            supersequence[i++] = str2[col - 1];
            col--;
        }
    }

    // Append any remaining characters
    // If there are leftover characters in str1
    while (row > 0) {
        supersequence[i++] = str1[row - 1];
        row--;
    }
    // If there are leftover characters in str2
    while (col > 0) {
        supersequence[i++] = str2[col - 1];
        col--;
    }

    // Reverse the built sequence to get the correct order
    supersequence[i] = 0;
    int left = 0, right = i - 1;
    char t;
    while(left < right) {
        t = supersequence[left];
        supersequence[left] = supersequence[right];
        supersequence[right] = t;
        left++; right--;
    }
    return supersequence;
}