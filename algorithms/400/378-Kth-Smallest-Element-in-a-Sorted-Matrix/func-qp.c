//Same as 786 pq-opt solution

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

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int n = matrixSize;
    unsigned int *heap = malloc(sizeof(Node) * n);
    int heapSize = -1;
    int i, j;
    for (i = 0; i < n; i++) {   // j = 0
        insert(heap, &heapSize, matrix[i][0], i, 0);
    }
    Node top;
    while(k > 0) {
        top.data = extractMax(heap, &heapSize);
        i = top.i;
        j = top.j;
        // printf("%d %d %d\n",i, j, top.value);
        if (j < n - 1) {
            insert(heap, &heapSize, matrix[i][j+1], i, j+1);
        }   
        k--;
    }
    free(heap);
    return top.value;
}