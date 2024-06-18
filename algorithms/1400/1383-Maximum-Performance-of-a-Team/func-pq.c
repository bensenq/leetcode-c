//priority queue: min heap
//same as 2542
//ref: https://leetcode.com/problems/maximum-subsequence-score/solutions/3082737/c-easiest-solution-using-priority-queue-with-explanation

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
    while (i > 0 && H[i] < H[parent(i)]) {
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
    if (l <= *size && H[l] < H[i]) {
        maxIndex = l;
    }
    // Right Child
    int r = rightChild(i);
    if (r <= *size && H[r] < H[maxIndex]) {
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

int compare (const void * a, const void * b){
    return (((int *)b)[1] - ((int *)a)[1]);
}


int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k) {
    int pair[n][2];
    for (int i = 0; i < n; i++) {
        pair[i][0] = speed[i];
        pair[i][1] = efficiency[i];
    }
    qsort(pair, n, sizeof(int*), compare);
    // for (int i = 0; i < nums1Size; i++)
    //     printf("%d, %d\n", pair[i][0], pair[i][1]);
    int heap[k];
    int heap_size = -1;
    long long sum = 0;
    long long ans = LLONG_MIN;
    sum = 0;
    for (int i = 0; i < n; i++) {
        insert(heap, &heap_size, pair[i][0]);
        sum += pair[i][0];
        if (heap_size <= k - 1) {
            long long val = sum * pair[i][1];
            ans = ans >= val ? ans : val;
        }
        if (heap_size == k - 1) {
            sum -= extractMax(heap, &heap_size);
        }
    }
    return ans % (1000000007);    
}