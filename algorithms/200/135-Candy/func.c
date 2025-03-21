int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) return 0;

    int up = 0;       // Length of the current ascending sequence
    int down = 0;     // Length of the current descending sequence
    int peak = 0;     // Peak value at the end of an ascending sequence
    int totalCandies = 1; // Start with one candy for the first child

    for (int i = 1; i < ratingsSize; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            // Ascending sequence
            up++;
            down = 0;
            peak = up + 1;
            totalCandies += peak;
        } else if (ratings[i] < ratings[i - 1]) {
            // Descending sequence
            up = 0;
            down++;
            totalCandies += down;
            if (peak <= down) {
                totalCandies++; // Adjust for the peak being part of the descending sequence
            }
        } else {
            // Flat sequence
            up = 0;
            down = 0;
            peak = 0;
            totalCandies += 1; // Reset to 1 candy for flat rating
        }
    }

    return totalCandies;
}