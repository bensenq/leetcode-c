// Iterative
int getSum(int a, int b) {
	if (a == 0)return b;
	if (b == 0)return a;

	while (b != 0) {
		/* bits will carry */
		carry = a & b;
		/* bits without carry */
		a = a ^ b;
		/* carried bits */
		b = carry << 1;
	}
	return a;
}

// Recursive
int getSum(int a, int b) {
	return (b == 0) ? a : getSum(a ^ b, (a & b) << 1);
}
