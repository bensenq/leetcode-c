void rotate(int* nums, int numsSize, int k){
    int shift;
    int *t;
    if (k  % numsSize == 0)  //no need to rotate
        return;
    
    shift =  k % numsSize;
    t = malloc(sizeof(int) * numsSize);
    memcpy(t, nums, sizeof(int) * numsSize);
    memcpy(nums+shift, t, (numsSize-shift)*sizeof(int));
    memcpy(nums, t+(numsSize-shift), shift*sizeof(int));
    free(t);
}