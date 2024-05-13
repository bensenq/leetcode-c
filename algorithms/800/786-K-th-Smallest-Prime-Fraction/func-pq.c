// priority queue method
// https://www.geeksforgeeks.org/priority-queue-using-binary-heap/

// C++ code to implement priority-queue using array implementation of binary heap

/* priority_queue start */
void swap(unsigned int *H, int a, int b) {
    unsigned int tmp = H[a];
    H[a] = H[b];
    H[b] = tmp;
}

// Function to return the index of the parent node of a given node
int parent(int i) {
    return (i - 1) / 2;
}
 
// Function to return the index of the left child of the given node
int leftChild(int i) {
    return ((2 * i) + 1);
}
 
// Function to return the index of the right child of the given node
int rightChild(int i) {
    return ((2 * i) + 2);
}
 
// Function to shift up the node in order to maintain the heap property
void shiftUp(unsigned int *H, int i, int *arr) {
    while (i > 0) {
        int p = H[i] & 0xffff, q = H[i] >> 16;
        int pp = H[parent(i)] & 0xffff, pq = H[parent(i)] >> 16;
        if((double)arr[p]/arr[q] < (double)arr[pp]/arr[pq]) { 
            // Swap parent and current node
            swap(H, parent(i), i); 
            // Update i to parent of i
            i = parent(i);
        } else break;
    }
}
 
// Function to shift down the node in order to maintain the heap property
void shiftDown(unsigned int *H, int *size, int i, int *arr) {
    int maxIndex = i;
    // Left Child
    int p = H[i] & 0xffff, q = H[i] >> 16;
    int l = leftChild(i);  
    if (l <= *size) {
        int lp = H[l] & 0xffff, lq = H[l] >> 16;
        if((double)arr[p]/arr[q] > (double)arr[lp]/arr[lq]) {
            maxIndex = l;
            p = lp;
            q = lq;
        }
    }
    // Right Child
    int r = rightChild(i);
    if (r <= *size) {
        int rp = H[r] & 0xffff, rq = H[r] >> 16;
        if((double)arr[p]/arr[q] > (double)arr[rp]/arr[rq])
            maxIndex = r;
    } 
    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H, i, maxIndex);
        shiftDown(H, size, maxIndex, arr);
    }
}
 
// Function to insert a new element in the Binary Heap
void insert(unsigned int *H, int* size, unsigned int p, int *arr)
{
    *size = *size + 1;
    H[*size] = p;
 
    // Shift Up to maintain heap property
    shiftUp(H, *size, arr);
}
 
// Function to extract the element with maximum priority
unsigned int *extractMax(unsigned int *H, int *size, int *arr)
{
    unsigned int result = H[0];
 
    // Replace the value at the root with the last leaf
    H[0] = H[*size];
    *size = *size - 1;
 
    // Shift down the replaced element to maintain the heap property
    shiftDown(H, size, 0, arr);
    return result;
}

/* priority_queue end */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
    int *result = malloc(sizeof(int) * 2);
    int n = arrSize;
    unsigned int *heap = malloc(sizeof(unsigned int) * (n*(n-1)/2));
    int heapSize = -1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            insert(heap, &heapSize, i | j << 16, arr);
        }
    }
    unsigned int r;
    while(k > 0) {
        r = extractMax(heap, &heapSize, arr);
        k--;
    }
    free(heap);
    result[0] = arr[r & 0xffff];
    result[1] = arr[r >> 16];
    *returnSize = 2;
    return result;
}