

bool isValid(char * s){
	int top = -1;			//empty
	char *stack;
	int i = 0;
	stack = malloc(strlen(s));
	while ( s[i] != 0 ) {
		if (s[i] == '[' || s[i] == '(' || s[i] == '{' ) {
			top++;			//push
			stack[top] = s[i];  	
		}
		else {
			if (top >= 0 && ((s[i] == ']' && stack[top] == '[') ||
				(s[i] == ')' && stack[top] == '(') ||
				(s[i] == '}' && stack[top] == '{')))
				top--;		//pop
			else {
				free(stack);
				return false;
			}
		}
		i++;
	}
	free(stack);
	if (top == -1)
		return true;
	else
		return false;
}

