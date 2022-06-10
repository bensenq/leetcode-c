#include <stdbool.h>
#include <stdlib.h>

typedef struct _record {
    int min;
    int max;
} record;

/* binary search */
bool searchUpdate(record* r, int* size, int val) {

    int result_index = *size - 1;

    /* find first r[i] that r[i].max is smaller than val */
    int left = 0, right = *size - 1, mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (r[mid].max <= val) {
            if(r[mid-1].max > val) {
                result_index = mid-1;
                break;
            }
            else 
                right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    /* check wether it is a 132 pattern */
    if (r[result_index].min < val && r[result_index].max > val)
        return true;

    /* otherwise update record array */
    r[result_index+1].min = r[*size - 1].min;
    r[result_index+1].max = val;
    *size = result_index + 2;

    return false;
}

bool find132pattern(int* nums, int numsSize){
    if (numsSize < 3)
        return 0;
    record *r = calloc(sizeof(record), (numsSize+1)/2);
    int rSize = 0;
    int i = 1;
    int start = 1;
    int min, max;
    int last_min = nums[0];
    while (i < numsSize) {
        if (rSize > 0) {
            if (nums[i] > min && nums[i] < max) {
                if (searchUpdate(r, &rSize, nums[i])) {
                    free(r);
                    return true;
                } else {
                    if (start == 1) {
                        r[rSize - 1].min = last_min;
                        min = last_min;
                        start = 0;
                    }
                }
            } else if (nums[i] <= min) {
                if (start == 0) {
                    start = 1;
                    last_min = nums[i];
                } else {
                    if (nums[i] < last_min) last_min = nums[i];
                    else if (nums[i] - last_min > 1) {
                        r[rSize].min = last_min;
                        r[rSize].max = nums[i];
                        rSize++;
                        min = last_min;
                        start = 0;
                    }
                }
            } else if (nums[i] >= max) {
                if (start == 0) {
                    min = r[rSize-1].min;
                } else {
                    min = last_min;                
                }
                max = nums[i];
                r[0].min = min;
                r[0].max = max;
                rSize = 1;
            }
        } else {    /* rSize == 0 */
            if (nums[i] - last_min > 1) {
                r[0].min = last_min;
                r[0].max = nums[i];
                min = last_min;
                max = nums[i];
                rSize = 1;
                start = 0;
            } else if (nums[i] < last_min) {
                last_min = nums[i];
            }
        }
        i++;
    }
    free(r);
    return false;
}

int main() {
    int test[]={40,50,25,35,15,35,20};
    return find132pattern(test,7);
}