int findComplement(int num) {
	int i;
	unsigned long t;
	for (i = 0; i < 32; i++) {
		t = (1 << i) - 1;
		if (num <= t)
			break;
	}
	return t - num;
}
