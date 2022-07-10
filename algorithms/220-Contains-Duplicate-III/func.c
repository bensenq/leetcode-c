#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define ABS(x) ((x) >= 0 ? (x) : -(x))

long long buckets_size;
long long buckets_count;
long long **buckets;

void buckets_init(long long size) {
    buckets_size = ceil(sqrt(size));
    buckets_count = size / buckets_size + 1;
    buckets = calloc(sizeof(long long *), buckets_count);   //0 means invalid
}

long long buckets_find(long long key) {
    long long index = key / buckets_size;
    long long offset = key % buckets_size;
    if (buckets[index] != 0 && buckets[index][offset] != 0)
        return buckets[index][offset];
    else
        return 0;
}

void buckets_insert(long long key, long long value) {
    long long index = key / buckets_size;
    long long offset = key % buckets_size;
    if (buckets[index] == 0)
        buckets[index] = calloc(sizeof(long long), buckets_size);   //0 means invalid
    buckets[index][offset] = value;    
}

void buckets_delete(long long key) {
    long long index = key / buckets_size;
    long long offset = key % buckets_size;
    buckets[index][offset] = 0;    
}

void buckets_fini() {
    for (int i = 0; i < buckets_count; i++) {
        if (buckets[i] != 0) 
            free(buckets[i]);
    }
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t){
    bool ret = false;
    long long min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max)
            max = nums[i];
        if (nums[i] < min)
            min = nums[i];
    }

    long long total_buckets_size = (max - min + 1) / ((long long)t + 1) + 2;   // total_buckets_size <= buckets_size * buckets_count
    buckets_init(total_buckets_size);
    for (int i = 0; i < numsSize; i++) {
        long long num = nums[i] - min + 1;    //map min to 1;
        long long index = num / ((long long)t+1);
        if (buckets_find(index) != 0) {
            ret = true;
            goto out;
        }

        //check prev bucket
        if (index > 0) {
            long long v = buckets_find(index - 1);
            if (v != 0 && ABS(v - num) <= t) {
                ret = true;
                goto out;
            }
        }

        //check next bucket
        if (index < total_buckets_size-1) {
            long long v = buckets_find(index + 1);
            if (v != 0 && ABS(v - num) <= t) {
                ret = true;
                goto out;
            }
        }
        
        buckets_insert(index, num);
   
        if (i >= k) {   // sliding window: pop related bucket
            num = nums[i-k] - min + 1;
            buckets_delete(num/((long long)t+1));
        }
    }    

out: 
    buckets_fini();     //free memory
    return ret;
}


int main() {
    int nums[] = {3,6,0,4};
    return containsNearbyAlmostDuplicate(nums, 4, 2, 2);
}