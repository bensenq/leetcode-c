typedef struct {
    int *array;
    int *prefix_sum;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *numArray = malloc(sizeof(NumArray));
    numArray->array = nums;
    int *prefix_sum = malloc(sizeof(int) * numsSize);
    prefix_sum[0] = nums[0];
    for(int i = 1; i < numsSize; i++) {
        prefix_sum[i] = prefix_sum[i-1] + nums[i];
    }
    numArray->prefix_sum = prefix_sum;
    return numArray;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if(left == 0) return obj->prefix_sum[right];
    else return obj->prefix_sum[right] - obj->prefix_sum[left - 1];
}

void numArrayFree(NumArray* obj) {
    free(obj->prefix_sum);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/
