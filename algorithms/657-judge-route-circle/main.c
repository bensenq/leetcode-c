bool judgeCircle(char* moves) {
	int x = 0, y = 0;
	int i;
	while(*moves != NULL) {
		switch (*moves) {
		case 'U': y++; break;
		case 'D': y--; break;
		case 'L': x++; break;
		case 'R': x--; break;
		}
		moves++;
	}
	if ((x == 0） && （y == 0))
		return true;
	else
		return false;
}
