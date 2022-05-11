int hammingDistance(int x, int y) {
	int i, distance;
	unsigned int t = x ^ y;
	distance = 0;
	for (i = 0; i < 31; i++) {
		if ((t & (1<<i)) != 0)
			distance++;	
	}
	return distance;
}

int main()
{
	int d = hammingDistance(1,4);
	return d;
}
