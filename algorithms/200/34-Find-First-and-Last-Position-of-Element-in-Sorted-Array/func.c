/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *result = malloc(sizeof(int) * 2);
    int left = 0, right = numsSize - 1, mid;
    *returnSize = 2; result[0] = -1; result[1] = -1;
    if (numsSize == 0) 
        return result;
    while (left <= right) {
        if (target < nums[left] || target > nums[right])
            break;

        mid = (left + right) / 2; 
        if (nums[mid] == target) {
            int i = mid;
            while(i >= 0 && nums[i] == target) {
                i--;
            }
            result[0] = ++i;
            i = mid;
            while(i < numsSize && nums[i] == target) {
                i++;
            }
            result[1] = --i;
            break;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int test[] = {5,7,7,8,8,10};
    int size;
    searchRange(test, 6, 8, &size);
}