#include <stdio.h>
extern int* twoSum(int* nums, int numsSize, int target);

int main(int argc, char *argv[])
{
	int nums[] = {3,2,4};
	int target = 6;
	int *result;
	result = twoSum(nums, 3, target);
	printf("result: %d, %d\n", result[0], result[1]);
}
