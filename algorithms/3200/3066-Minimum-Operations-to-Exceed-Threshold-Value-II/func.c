#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For UINT_MAX

/* priority queue implementation using min-heap */

// Function to swap two unsigned integers
void swap(unsigned int *a, unsigned int *b) {
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

// Min-Heap implementation
typedef struct {
    unsigned int *arr;
    int capacity;
    int size;
} MinHeap;

// Function to create a min-heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->arr = (unsigned int*)malloc(capacity * sizeof(unsigned int));
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Function to heapify a subtree with the root at given index
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&heap->arr[idx], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

// Function to insert a new element into the heap
void insert(MinHeap* heap, unsigned int val) {
    if (heap->size == heap->capacity) {
        printf("Heap is full!\n");
        return;
    }

    heap->arr[heap->size++] = val;
    int i = heap->size - 1;

    while (i != 0 && heap->arr[(i - 1) / 2] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the minimum element from the heap
unsigned int extractMin(MinHeap* heap) {
    if (heap->size <= 0)
        return UINT_MAX; // Return a sentinel value indicating error

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    unsigned int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

// Function to get the minimum element (heap top) without removing it
unsigned int getMin(MinHeap* heap) {
    if (heap->size <= 0)
        return UINT_MAX; // Return a sentinel value indicating error
    return heap->arr[0];
}

/* priority queue implementation ends here */

// Main function to calculate the minimum number of operations
int minOperations(unsigned int* nums, int numsSize, unsigned int k) {
    MinHeap* heap = createMinHeap(numsSize);

    // Insert all elements into the heap
    for (int i = 0; i < numsSize; i++) {
        insert(heap, nums[i]);
    }

    // Initial check: if the heap top is already >= k, return 0
    if (getMin(heap) >= k) {
        free(heap->arr);
        free(heap);
        return 0;
    }

    int operations = 0;

    // Perform operations until the heap top is >= k
    while (getMin(heap) < k && heap->size >= 2) {
        unsigned int x = extractMin(heap);
        unsigned int y = extractMin(heap);

        // Calculate newElement using unsigned long long to avoid overflow
        unsigned int newElement = (x < y ? x : y) * 2 + (x > y ? x : y);

        insert(heap, newElement);
        operations++;
    }

    // Free the heap memory
    free(heap->arr);
    free(heap);

    return operations;
}