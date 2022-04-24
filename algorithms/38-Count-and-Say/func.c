char *say(char *digits) {
    char *result;
    int i = 1, j = 0;
    int repeat = 1;
    char last_number = digits[0];
    result = calloc(2*strlen(digits)+1, 1);
    while (digits[i] != 0) {
        if(digits[i] == last_number) {
                repeat++;
        } else {
            result[j++] = repeat + '0';
            result[j++] = last_number;
            repeat = 1;
            last_number = digits[i];    
        }
        i++;
    }
    result[j++] = repeat + '0';
    result[j++] = last_number;
    return result;
}

char * countAndSay(int n){
    char * result = result = strdup("1");
    char * ret;
    int c = 0;
    if (n == 1)
        goto out;
    c = 1;
    while (c < n) {
        ret = say(result);
        free(result);
        result = ret;
        c++;
    }

out:
    return result;
}

int main()
{
    printf("%s\n", countAndSay(4));
    return 0;
}