int romanToInt(char * s){
	int i = 0;
	int value = 0;
	while (s[i] != 0) {
		switch (s[i]) {
			case 'M':
				value += 1000;
				break;
			case 'D':
				value += 500;
				break;
			case 'C':
				if (s[i+1] == 'M' || s[i+1] == 'D')
					value -= 100;
				else
					value += 100;
				break;
			case 'L':
				value += 50;
				break;
			case 'X':
				if (s[i+1] == 'C' || s[i+1] == 'L')
					value -= 10;
				else
					value += 10;
				break; 
			case 'V':
				value += 5;
				break;
			case 'I':
				if (s[i+1] == 'X' || s[i+1] == 'V')
					value -= 1;
				else
					value += 1;
				break; 
		}
		i++;
	}
	return value;
}
