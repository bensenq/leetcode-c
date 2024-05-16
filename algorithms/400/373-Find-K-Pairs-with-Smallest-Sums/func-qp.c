//Same as 378 pq-opt solution

// priority queue method optimized for ordered matrix
// https://www.geeksforgeeks.org/priority-queue-using-binary-heap/

// C code to implement priority-queue using array implementation of binary heap

typedef union {
    struct {
        int value;
        short i;
        short j;
    };
    unsigned long long data;
} Node;

/* priority_queue start */
void swap(Node *H, int a, int b) {
    unsigned long long tmp = H[a].data;
    H[a].data = H[b].data;
    H[b].data = tmp;
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
void shiftUp(Node *H, int i) {
    while (i > 0 && H[i].value < H[parent(i)].value) {
        // Swap parent and current node
        swap(H, parent(i), i); 
        // Update i to parent of i
        i = parent(i);
    }
}
 
// Function to shift down the node in order to maintain the heap property
void shiftDown(Node *H, int *size, int i) {
    int maxIndex = i;
    // Left Child
    int l = leftChild(i);  
    if (l <= *size && H[l].value < H[i].value) {
        maxIndex = l;
    }
    // Right Child
    int r = rightChild(i);
    if (r <= *size && H[r].value < H[maxIndex].value) {
        maxIndex = r;
    }
    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H, i, maxIndex);
        shiftDown(H, size, maxIndex);
    }
}
 
// Function to insert a new element in the Binary Heap
void insert(Node *H, int* size, int p, int i, int j)
{
    *size = *size + 1;
    H[*size].value = p;
    H[*size].i = i;    
    H[*size].j = j;
    // Shift Up to maintain heap property
    // printf("insert %d %d %d\n", i, j, p);
    shiftUp(H, *size);
}
 
// Function to extract the element with maximum priority
unsigned long long extractMax(Node *H, int *size)
{
    unsigned long long result = H[0].data;
 
    // Replace the value at the root with the last leaf
    H[0].data = H[*size].data;
    *size = *size - 1;
 
    // Shift down the replaced element to maintain the heap property
    shiftDown(H, size, 0);
    return result;
}

/* priority_queue end */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(sizeof(int *) * k);
    *returnColumnSizes = malloc(sizeof(int) * k);
    *returnSize = k;

    unsigned int *heap = malloc(sizeof(Node) * nums1Size);
    int heapSize = -1;
    int c = 0;
    int i, j;
    for (i = 0; i < k; i++) {
        result[i] = malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }

    for (i = 0; i < nums1Size; i++) {
        insert(heap, &heapSize, nums1[i]+nums2[0], i, 0);
    }

    Node top;
    while (c < k) {
        top.data = extractMax(heap, &heapSize);
        i = top.i;
        j = top.j;
        result[c][0] = nums1[i];
        result[c][1] = nums2[j];
        // printf("%d %d %d\n",i, j, top.value);
        if (j < nums2Size - 1) {
            insert(heap, &heapSize, nums1[i]+nums2[j+1], i, j+1);
        }   
        c++;
    }
    free(heap);
    return result;
}