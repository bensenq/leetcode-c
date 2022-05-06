int missingNumber(int* nums, int numsSize){
    int i = 0;
    int expect = (numsSize)*(numsSize+1)/2;
    while(i < numsSize) {
        expect -= nums[i++];
    }
    return expect;
}