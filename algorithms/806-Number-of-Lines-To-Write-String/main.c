/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
	int i;
	int lines = 1;
	int last_line = 0;
	int total_letters = 0;
	int *ret = malloc(sizeof(int) * 2);
	while (*S != 0) {
		int width = widths[*S-'a'];
		if(last_line + width > 100) {
			lines++;
			last_line = width;
		} else
			last_line += width;
		S++;
	}

	if (lines == 1 && last_line = 0)
		ret[0] = 0;
	else
		ret[0] = lines;
	ret[1] = last_line;
	*returnSize = 2;
	return ret;
}

int main()
{
	int widths[26] = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	char *S = "bbbcccdddaaa";
	int a;
	numberOfLines(widths, 26, S, &a);
	return 0;
}
