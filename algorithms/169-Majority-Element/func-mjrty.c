//Boyer-Moore Majority Vote Algorithm
//http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
int majorityElement(int* nums, int numsSize) {
    int major = nums[0], count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            count++;
            major = nums[i];
        } else if (major == nums[i]) {
            count++;
        } else count--;
    }
    return major;
}