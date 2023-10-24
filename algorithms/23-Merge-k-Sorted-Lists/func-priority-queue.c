
// https://www.geeksforgeeks.org/priority-queue-using-binary-heap/

// C++ code to implement priority-queue using array implementation of binary heap


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// #include <stdlib.h>

// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

/* priority_queue start */

void swap(struct ListNode **H, int a, int b) {
    struct ListNode *tmp = H[a];
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
void shiftUp(struct ListNode **H, int i) {
    printf("shiftUp, i: %d, parent i:%d\n", i, parent(i));
    while (i > 0 && H[parent(i)]->val > H[i]->val) { 
        // Swap parent and current node
        swap(H, parent(i), i); 
        // Update i to parent of i
        i = parent(i);
    }
}
 
// Function to shift down the node in order to maintain the heap property
void shiftDown(struct ListNode **H, int *size, int i) {
    int maxIndex = i;
    // Left Child
    int l = leftChild(i);
    if (l <= *size && H[l]->val < H[maxIndex]->val) {
        maxIndex = l;
    }
    // Right Child
    int r = rightChild(i);
    if (r <= *size && H[r]->val < H[maxIndex]->val) {
        maxIndex = r;
    } 
    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H, i, maxIndex);
        shiftDown(H, size, maxIndex);
    }
}
 
// Function to insert a new element in the Binary Heap
void insert(struct ListNode **H, int* size, struct ListNode *p)
{
    *size = *size + 1;
    H[*size] = p;
 
    // Shift Up to maintain heap property
    shiftUp(H, *size);
}
 
// Function to extract the element with maximum priority
struct ListNode *extractMax(struct ListNode **H, int *size)
{
    struct ListNode *result = H[0];
 
    // Replace the value at the root with the last leaf
    H[0] = H[*size];
    *size = *size - 1;
 
    // Shift down the replaced element to maintain the heap property
    shiftDown(H, size, 0);
    return result;
}

/* priority_queue end */

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (listsSize == 0)
        return 0;
    struct ListNode dummy;
    struct ListNode *t = &dummy;
    struct ListNode *result = t;
    //count total size, could be optimized by 
    //allocating largest memory considering constraints.
    int totalSize  = 0;
    for (int i = 0; i < listsSize; i++) {
        struct ListNode * p = lists[i];
        while(p != 0) {
            totalSize++;
            p = p->next;
        }
    }

    //init a priority queue
    struct ListNode **H = malloc(sizeof(struct ListNode *) * totalSize);
    int heapSize = -1;

    //push all nodes to queue
    for (int i = 0; i < listsSize; i++) {
        struct ListNode *p = lists[i];
        while(p != 0) {
            insert(H, &heapSize, p);
            p = p->next;
        }
    }

    while (heapSize >= 0) {
        t->next = extractMax(H, &heapSize);
        t = t->next;
    }
    t->next = 0;
    free(H);
    return result->next;
}