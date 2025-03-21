// ref: https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/

// Transform and calculate synchronously

// Function to return precedence of operators
int prec(char c) {
    if (c == '/' || c == '*')
        return 2;
    return 1;   //'+' and '-'
}

int calculate(char* s) {
    int num_stack[3];
    int num_top = -1;
    char op_stack[2];   // 2 is enough in "*/+-"" without "()"
    int op_top = -1;
    int num, result, op1, op2;

    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == ' ') {
            continue;
        } else if (isdigit(s[i])) {
            num = s[i] - '0';
            while (s[i+1] != 0 && isdigit(s[i+1])) {
                num = num * 10 + (s[++i] - '0');
            }
            num_stack[++num_top] = num;
        } else {    // +-/*
            while (op_top != -1 && (prec(s[i]) < prec(op_stack[op_top]) || prec(s[i]) == prec(op_stack[op_top]))) {
                op1 = num_stack[num_top-1];
                op2 = num_stack[num_top];
                switch (op_stack[op_top--]){
                    case '+': result = op1 + op2; break;
                    case '-': result = op1 - op2; break;
                    case '*': result = op1 * op2; break;
                    case '/': result = op1 / op2; break;
                }
                num_stack[--num_top] = result;
            } 
            op_stack[++op_top] = s[i];
        }
    }

    //pop all operator
    while(op_top >= 0) {
        op1 = num_stack[num_top-1];
        op2 = num_stack[num_top];
        switch (op_stack[op_top--]){
            case '+': result = op1 + op2; break;
            case '-': result = op1 - op2; break;
            case '*': result = op1 * op2; break;
            case '/': result = op1 / op2; break;
        }
        num_stack[--num_top] = result;
    }

    return num_stack[0];
}