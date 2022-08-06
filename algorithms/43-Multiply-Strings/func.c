//ref: https://leetcode.com/problems/multiply-strings/discuss/17605/Easiest-JAVA-Solution-with-Graph-Explanation
/*
public String multiply(String num1, String num2) {
    int m = num1.length(), n = num2.length();
    int[] pos = new int[m + n];
   
    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0'); 
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + pos[p2];

            pos[p1] += sum / 10;
            pos[p2] = (sum) % 10;
        }
    }  
    
    StringBuilder sb = new StringBuilder();
    for(int p : pos) if(!(sb.length() == 0 && p == 0)) sb.append(p);
    return sb.length() == 0 ? "0" : sb.toString();
}
*/


char * multiply(char * num1, char * num2){
    int m = strlen(num1), n = strlen(num2);
    int len = m + n;
    char *result = calloc(len + 1, 1);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            char mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            char sum = mul + result[p2];
            result[p1] += sum / 10;
            result[p2] = sum % 10;
        }
    }

    int j = 0;
    while(j < len && result[j] == 0) { j++; }
    if (j == len) {
        result[0] = 0;
        result[1] = 0;
        result = realloc(result, 2);
        len = 1;
    } else if (j != 0) {
        len -= j;
        char *tmp = malloc(len + 1);
        memcpy(tmp, result+j, len + 1);
        free(result);
        result = tmp;
    }

    for (int i = 0; i < len; i++) {
        result[i] += '0';
    }    
    return result;
}


int main() {
    multiply("123","456");
}