void sort_bubble(char *s, int len) {
	int i, j, t;
	if (len == 1) return;
	for (j = len; j >= 2; j--) {
		for (i = 0; i < j-1; i++) {
			if (s[i] > s[i+1]) {
				t = s[i+1];
				s[i+1] = s[i];
				s[i] = t;
			}
		}
	}

}

void sort_select(char *s, int len) {
        int i, j, t, min;
        if (len == 1) return;
        for (j = 0; j < len-1; j++) {
                min = j;
                for (i = j+1; i < len; i++) {
                        if (s[i] < s[min])
                                min = i;
                }
                t = s[j];
                s[j] = s[min];
                s[min] = t;
        }
}


void sort_insert(char *s, int len) {
        int i, j, t;
        if (len == 1) return;
        for (j = 1; j < len; j++) {
                int t = s[j]; 
                for (i = j-1; i >= 0; i--) {
                        if (t < s[i]) {
                                s[i+1] = s[i];
                        } else {
                                break;
                        }
                }
                s[i+1] = t;
        }
}

char * sortString(char * s){
	int i, len;
	char *result;
	int index = 0;
	len = strlen(s);
	result = malloc(len+1);

//	sort_bubble(s, len);
//	sort_select(s, len);
	sort_insert(s, len);

	printf("%s\n", s);

	while (1) {
		/* step 1 */
		if (index == len)
			break;
		for (i = 0; i < len; i++) {
			if (s[i] != 0) {
				result[index] = s[i];
				index += 1;
				s[i] = 0; /* picked */
				break;
			}
		}


		/* step 2-3 */
		if (index == len)
			break;
		for (i = 0; i < len; i++) {
			if (s[i] != 0 && s[i] > result[index-1]) {	
				result[index] = s[i];
				index += 1;
				s[i] = 0; /* picked */
			}
		}

		/* step 4 */
		if (index == len)
			break;
		for (i = len-1; i >= 0; i--) {
			if (s[i] != 0) {
				result[index] = s[i];
				index += 1;
				s[i] = 0; /* picked */
				break;
			}
		}

		/* step 5-6 */
		if (index == len)
			break;
		for (i = len-1; i >= 0; i--) {
			if (s[i] != 0 && s[i] < result[index-1]) {	
				result[index] = s[i];
				index += 1;
				s[i] = 0; /* picked */
			}
		}
	}
	result[index] = 0;
	printf("%s\n", result);
	return result;
}

int main() {
	char *s = strdup("aaaabbbbcccc");	
	sortString(s);
	return 0;
}
