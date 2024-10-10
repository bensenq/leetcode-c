/* monotonic stack */
int maxWidthRamp(const int * const nums, const int numsLen){
	int maxLen = 0;
	int stack[numsLen];
	int stackLen = 0;

	stack[stackLen] = 0;
	stackLen += 1;

    /* construct monostack */
	for (int i = 1; i < numsLen; i++){
		if (nums[i] < nums[ stack[stackLen - 1] ]){
			stack[stackLen] = i;
			stackLen += 1;
		}
	}

	for (int i = numsLen - 1; i >= 0; i--){
		if (stackLen == 0){
			break;
		}

		while (stackLen >= 1 && nums[i] >= nums[stack[stackLen - 1]]){
			const int curLen = i - stack[stackLen - 1];
			if (curLen > maxLen){
				maxLen = curLen;
			}
			stackLen--;
		}
	}

	return maxLen;
}
