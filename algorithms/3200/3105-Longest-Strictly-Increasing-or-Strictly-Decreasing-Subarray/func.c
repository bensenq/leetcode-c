int longestMonotonicSubarray(int* nums, int numsSize) {
    int longest = 1;
    int inc = 1, dec = 1;
    for(int i = 1; i < numsSize; i++) {
        bool check_inc = false, check_dec = false;
        if(nums[i] > nums[i-1]) {
            check_dec = true;
            inc++;
        } else if (nums[i] < nums[i-1]) {
            check_inc = true;
            dec++;
        } else {
            check_inc = true; check_dec = true;
        }
        if(check_dec && dec != 1){
            if (dec > longest) longest = dec;
            dec = 1;
        }
        if(check_inc && inc != 1) {
            if (inc > longest) longest = inc;
            inc = 1;
        }
    }

    if (dec != 1 && dec > longest) longest = dec;    
    if (inc != 1 && inc > longest) longest = inc;    
    return longest;
}
