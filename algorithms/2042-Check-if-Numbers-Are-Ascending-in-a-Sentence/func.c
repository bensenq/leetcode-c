#define bool int

bool areNumbersAscending(char * s){
    int i, j;
    int value, last = 0;
    int result;
    char number[3]; // enough: 2 <> 200
    int step;
    i = 0;
    while(s[i] != 0) {
        if (s[i] >= '0' && s[i] <= '9') {
            /* finding a number */
            j = 0;
            do {
                number[j] = s[i] - '0';
                j++; i++;
            } while(s[i] != 0 && s[i] >= '0' && s[i] <= '9');
            if (s[i] == 0)
                break;

            /* calculate value */
            step = 1;
            value = 0;
            while (j > 0) {
                value += number[j-1]*step;
                step *= 10;
                j--;
            }

            /* check value */
            if (value <= last) {
                result = 0; //false
                goto out;
            } else {
                last = value;
            }
        }
        i++;
    }
    result = 1; //true

out:
    return result;
}

void main() {
//    areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles");    
    areNumbersAscending("hello world 5 x 5"); 
}