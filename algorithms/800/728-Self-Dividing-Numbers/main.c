/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
	int i, j, k;
	int *result = malloc(sizeof(int) * (right-left+1));
	int size = 0;
	int digit[4];
	i = left;
	if (right == 10000)
		right = 9999;

	while (i <= right) {
		int has_zero = 0;
		int len;
		int flag;
		if (i < 10) {
			len = 1;
			digit[0] = i;
			goto nocheck;
		}
		else if (i < 100) {
			digit[1] = i / 10;
			len = 2;
			goto check_100;
		}
		else if (i < 1000) {
			digit[2] = i / 100;
			len = 3;
			goto check_1000;
		}
		else if (i < 10000) {
			digit[3] = i / 1000;
			len = 4;
			goto check_10000;
		}
check_10000:
		digit[2] = (i % 1000) / 100;
		if (digit[2] == 0) {
			i = i+100 - (i+100)%100 ;
			has_zero = 1;
		}
check_1000:
		digit[1] = (i % 100) / 10;
		if (digit[1] == 0) {
			i = i+10 - (i+10)%10;
			has_zero = 1;
		}
check_100:
		digit[0] = i % 10;
		if (digit[0] == 0) {
			i++;
			has_zero = 1;
		}
		if(has_zero)
			continue;
nocheck:

		flag = 1;
		for (j = 0; j < len; j++) {
			if (i % digit[j] != 0) {
				flag = 0;
				break;
			}
		}

		if (flag == 1) {
			result[size] = i;
			size++;
		}
		i++;
	}
	*returnSize = size;
	return result;
}

int main(void)
{
	int size;
	selfDividingNumbers(1, 22, &size);
}
