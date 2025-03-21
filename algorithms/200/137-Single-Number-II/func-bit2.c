/*
 * When a bit appears for the first time (ones is 0 and the bit is toggled), it is stored in ones.
 * When a bit appears for the second time (ones is 1 and the bit is toggled), it is removed from ones and stored in twos.
 * When a bit appears for the third time (ones is 0 and the bit is toggled), it is removed from both ones and twos.
 */

int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    
    for (int i = 0; i < numsSize; i++) {
        // Update 'ones' with the current number and bits in 'twos'
        ones = (ones ^ nums[i]) & ~twos;
        // Update 'twos' with the current number and bits in 'ones'
        twos = (twos ^ nums[i]) & ~ones;
    }
    
    return ones;
}