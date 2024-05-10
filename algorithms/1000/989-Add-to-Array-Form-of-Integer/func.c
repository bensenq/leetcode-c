#define max(a,b) (a > b ? a : b)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize){
    int sum5 = 0;
    int resultLen = max(5, numSize);
    int *result;
    int i;
    int ratio;
    int carry = 0;

    i = 1;
    ratio = 1;
    while (i <= 5 && (numSize-i) >= 0) {
        sum5 += num[numSize-i]*ratio;
        ratio *= 10;
        i++;
    }

    sum5 += k;
    carry = sum5 / 100000;
    sum5 %= 100000;

    if (resultLen == 5) {
        int j = 0, n = 0;
        int leading = 1;
        result = malloc(sizeof(int) * 6);
        if (carry == 1) {
            result[j++] = 1;
            leading = 0;
        }
        ratio = 10000;
        while (n < 5) {
            int x = sum5 / ratio;
            if (x == 0 && leading == 0) {
                result[j++] = 0;
            } else if(x != 0) {
                result[j++] = x;
                if(leading == 1) leading = 0;
            }
            sum5 %= ratio;
            ratio /= 10;
            n++;
        }
        if (j != 6) {
            result = realloc(result, sizeof(int) * j);
        }
        *returnSize = j;    
    } else {
        int j;
        result = malloc(sizeof(int) * numSize);
        memcpy(result, num, sizeof(int)*(numSize - 5));
        j = numSize - 5;
        *returnSize = numSize;
        ratio = 10000;
        while (j < numSize) {
            result[j] = sum5 / ratio;
            sum5 %= ratio;
            ratio /= 10;
            j++;
        }
        if (carry == 1) {
            j = numSize - 6;
            while (j >= 0 && carry == 1) {
                result[j] += carry;
                carry = result[j] / 10;
                result[j] %= 10;
                j--;
            }
            if (carry == 1) {
                int * tmp = result;
                result = malloc(sizeof(int) * (numSize + 1));
                result[0] = 1;
                memcpy(&result[1], tmp, sizeof(int)*numSize);
                free(tmp);
                *returnSize = numSize + 1;
            }
        }
    }
    return result;
}

int main() {
    int num[] = {9,7,4,5,5,3,0,3,7,1,6,5,8,8,9,9,0,5,8,0,2,5,8,2,9,4,2,5,7,2,8,5,0,4,1,9,0,8,8,0,1,5,5,6,4,9,9,0,9,4};
    int retSize;
    int *ret;
    ret = addToArrayForm(num, sizeof(num)/sizeof(num[0]), 7544, &retSize);
    free(ret);
    return 0;
}