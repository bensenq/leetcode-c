/* algo: find the min and max str in array, and then cmp min and max*/
char * longestCommonPrefix(char ** strs, int strsSize){
	int max, min;
	char *result = "";
	int i = 1;
	if (strsSize == 0) {
		goto out;
	} else {
		max = min = 0;
	}
	while(i < strsSize) {
		if (strcmp(strs[i], strs[max]) > 0) {
			max = i;
		} else if (strcmp(strs[i], strs[min]) < 0) {
			min = i;
		}
		i++; 
	}
	i = 0;
	while(strs[max][i] != 0 && strs[min][i] != 0
			&& strs[max][i] == strs[min][i]) {
		i++;
	}
	result = malloc(i+1);
	strncpy(result, strs[max], i);
	result[i] = 0;
out:
	return result;
}
