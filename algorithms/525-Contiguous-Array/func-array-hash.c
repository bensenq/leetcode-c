int findMaxLength(int* nums, int numsSize) {
    int max = 0;
    int *count = calloc(sizeof(int), numsSize * 2 + 1);
    int i = 0;
    int sum = 0;
    int index;
    count[numsSize] = 1;
    while(i < numsSize) {
        if (nums[i] == 0) sum--;
        else sum++;
        index = sum + numsSize;
        if (count[index] == 0) {
            count[index] = i + 2;
        } else {
            int new_index = i + 2;
            if(new_index - count[index] > max)
                max = new_index - count[index];
        }
        i++;
    }
    free(count);
    return max;
}

int main() {
    int data[] = {0,0,1};
    return findMaxLength(data, sizeof(data)/sizeof(data[0]));
}