/* algo: two pointer */
#define min(a,b) a <= b ? a : b
int maxArea(int* height, int heightSize) {
	int left = 0, right = heightSize - 1, result = 0;
	int depth, width;
	int water;
	while (left < right) {
		depth = min(height[left], height[right]);
		width = right - left;
		water = depth * width;
		if (water > result) {
			result = water;
		}
		if (height[left] < height[right])
			left++;
		else 
			right--;
	}
	
	return result;
}

