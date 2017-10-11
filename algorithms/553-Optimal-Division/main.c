#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * max: 1 for find max; 0 for find min
 * result: the max/min value
 * ret: expression string
 */
char *findDivision(int *nums, int numsSize, int max, float *result) {
	char *ret = malloc(200);
	memset(ret, 0, 200);
	if (numsSize == 1) {
		sprintf(ret, "%d", nums[0]);
		*result = nums[0];
		return ret;
	} else {
		float value = 0;
		int i;
		float t1, t2;
		char *r1 = 0, *r2 = 0, *tr1, *tr2;
		int useParenthesis = 1;
		for (i = 1; i < numsSize; i++) {
			if (max) {
				tr1 = findDivision(nums, i, 1, &t1); //find max
				tr2 = findDivision(nums+i, numsSize-i, 0, &t2); //find min
				if ((value == 0) || (float)(t1)/(float)(t2) > value) {
					value = (float)(t1)/(float)(t2);
					if (r1) free(r1);
					if (r2) free(r2);
					r1 = tr1;
					r2 = tr2;
					if ((numsSize-i) == 1)
						useParenthesis = 0;
				}
			} else {
				tr1 = findDivision(nums, i, 0, &t1); //find max
				tr2 = findDivision(nums+i, numsSize-i, 1, &t2); //find min
				if ((value == 0) || (float)(t1)/(float)(t2) < value) {
					value = (float)(t1)/(float)(t2);
					if (r1) free(r1);
					if (r2) free(r2);
					r1 = tr1;
					r2 = tr2;
					if ((numsSize-i) == 1)
						useParenthesis = 0;
				}
			}
		}
		*result = value;
		if (useParenthesis)
			sprintf(ret, "%s/(%s)", r1, r2);
		else 
			sprintf(ret, "%s/%s", r1, r2);
		free(r1);
		free(r2);
		return ret;
	}
}

char* optimalDivision(int* nums, int numsSize) {
	float result;
	char *ret;
	ret = findDivision(nums, numsSize, 1, &result);
	return ret;
}

#ifdef TEST
int main()
{
	//int nums[] = {1000,100,10,2};
	int nums[] = {2, 3, 4};
	char *ret;
	ret = optimalDivision(nums, 3);
	return 0;
}
#endif
