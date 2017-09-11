/* c: input complex str
 * a: output real part
 * b: output virtual part
 */

void getab(char *c, char *a, char *b) 
{
	char *t;
	*a = strtol(c, &t, 10);
	*b = strtol(t+1, &t, 10);
	return;
}

char* complexNumberMultiply(char* a, char* b) 
{
	/* 
	 * a = aa + ab*i; 
	 * b = ba + bb*i; 
	 * a * b = (aa + ab*i) * (ba + bb*i) 
	 * 	 = aa*ba + aa*bb*i + ab*ba*i - ab*bb
	 * 	 = (aa*ba - ab*bb) + (aa*bb + ab*ba)*i
	 * 	 = ca + cb*i
	 */
	char aa, ab, ba, bb,
	int ca, cb;
	char *c = malloc(16);
	getab(a, &aa, &ab);
	getab(b, &ba, &bb);
	ca = aa*ba - ab*bb;
	cb = aa*bb + ab*ba;
	snprintf(c, 16, "%d+%di", ca, cb);
	return c;
}
