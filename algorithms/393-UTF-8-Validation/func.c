#include <stdbool.h>
bool validUtf8(int* data, int dataSize) {
    int i = 0;
    int result;
    int new = 1;
    int expect = 0;
    while(i < dataSize) {
        if (new) {
            if ((data[i] & 1 << 7) != 0) {    /* 1xxxxxxx */
                if ((data[i] & 1 << 6) == 0) {   /* 10xxxxxx */
                    break;
                } else if ((data[i] & 1 << 5) == 0) {    /* 110xxxxx */
                    new = 0;
                    expect = 1;
                } else if ((data[i] & 1 << 4) == 0) {    /* 1110xxxx */
                    new = 0;
                    expect = 2;
                } else if ((data[i] & 1 << 3) == 0) {    /* 11110xxx */
                    new = 0;
                    expect = 3;
                } else {
                    break;
                }
            }
        } else {
            if ((data[i] & 3 << 6) != 0x80) {
                break;
            } else {
                expect--;
                if(expect == 0) new = 1;
            }
        }
        i++;
    }
    if (i != dataSize || i == dataSize && new == 0) result = false; 
    else result = true;
        
    return result;
}

int main(){
    int data[] = {197,194,1};
    return validUtf8(data, sizeof(data)/sizeof(data[0]));
}