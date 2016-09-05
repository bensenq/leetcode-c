int getSum(int a, int b) {
	int ret;

	/* a + b = a + (b/a * a + b%a) = a(1+b/a) + b%a */

	int times;
	long aa = a >= 0 ? a : (-1*(long)a);
	long bb = b >= 0 ? b : (-1*(long)b);
	if (a == 0)
		ret = b;
	else if (b == 0)
		ret = a;
	else if (aa > bb) {
		times = a / b;
		ret = b*(++times) + a%b;
	} else {
		times = b / a;
		ret = a*(++times) + b%a;
	}

	return ret;
}
