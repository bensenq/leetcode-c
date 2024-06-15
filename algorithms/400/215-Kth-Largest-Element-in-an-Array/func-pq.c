/* priority queue: max heap */

// C code to implement priority-queue using array implementation of binary heap

/* priority_queue start */
void swap(int *H, int a, int b) {
    int tmp = H[a];
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
void shiftUp(int *H, int i) {
    while (i > 0 && H[i] > H[parent(i)]) {
        // Swap parent and current node
        swap(H, parent(i), i); 
        // Update i to parent of i
        i = parent(i);
    }
}
 
// Function to shift down the node in order to maintain the heap property
void shiftDown(int *H, int *size, int i) {
    int maxIndex = i;
    // Left Child
    int l = leftChild(i);  
    if (l <= *size && H[l] > H[i]) {
        maxIndex = l;
    }
    // Right Child
    int r = rightChild(i);
    if (r <= *size && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H, i, maxIndex);
        shiftDown(H, size, maxIndex);
    }
}
 
// Function to insert a new element in the Binary Heap
void insert(int *H, int* size, int k)
{
    *size = *size + 1;
    H[*size] = k;
    // Shift Up to maintain heap property
    // printf("insert %d %d %d\n", i, j, p);
    shiftUp(H, *size);
}
 
// Function to extract the element with maximum priority
int extractMax(int *H, int *size)
{
    int result = H[0];
 
    // Replace the value at the root with the last leaf
    H[0] = H[*size];
    *size = *size - 1;
 
    // Shift down the replaced element to maintain the heap property
    shiftDown(H, size, 0);
    return result;
}

/* priority_queue end */

int findKthLargest(int* nums, int numsSize, int k) {
    int *heap = malloc(sizeof(int) * numsSize);
    int size = -1;
    int ans;
    for(int i = 0; i < numsSize; i++)
        insert(heap, &size, nums[i]);
    for(int i = 0; i < k - 1; i++)
        extractMax(heap, &size);
    ans = extractMax(heap, &size);
    free(heap);
    return ans;
}