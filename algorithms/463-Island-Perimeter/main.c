int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
	int i, j;
	int count = 0;
	int inner_side = 0;
	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j] == 1) {
				count++;
				/* up */
				if (i != 0) {
					if (grid[i-1][j] == 1)
						inner_side++;
				}

				/* down */
				if (i != (gridRowSize-1)) {
					if (grid[i+1][j] == 1)
						inner_side++;
				}

				/* left */
				if (j != 0) {
					if (grid[i][j-1] == 1)
						inner_side++;
				}

				/* right */
				if (j != (gridColSize-1)) {
					if (grid[i][j+1] == 1)
						inner_side++;
				}
			}
		}
	}
	return count*4 - inner_side;
}
