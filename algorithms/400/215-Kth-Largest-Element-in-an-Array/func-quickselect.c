/* quick select */
//ref: https://leetcode.com/problems/kth-largest-element-in-an-array/solutions/60309/c-stl-partition-and-heapsort/

void swap(int *nums, int i, int j) {
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

int partition(int* nums, int left, int right) {
    int pivot = nums[left], l = left + 1, r = right;
    while (l <= r) {
        if (nums[l] < pivot && nums[r] > pivot) {
            swap(nums, l++, r--);
        }
        if (nums[l] >= pivot) {
            l++;
        }
        if (nums[r] <= pivot) {
            r--;
        }
    }
    swap(nums, left, r);
    return r;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int left = 0, right = numsSize - 1, kth;
    while (true) {
        int idx = partition(nums, left, right);
        if (idx == k - 1) {
            kth = nums[idx];
            break;
        }
        if (idx < k - 1) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }
    return kth;
}