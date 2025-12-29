/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Structure for dynamic 2D integer array to store results
struct IntArray2D {
    int **data;      // Pointer to 2D array
    int size;        // Current number of paths
    int capacity;    // Array capacity
    int *cols;       // Length of each path
};

// Structure for dynamic 1D integer array to store current path
struct IntArray {
    int *data;       // Pointer to array
    int size;        // Current number of elements
    int capacity;    // Array capacity
};

// Initialize a 1D dynamic array
void initIntArray(struct IntArray *arr) {
    arr->capacity = 16;  // Initial capacity
    arr->size = 0;       // Empty array
    arr->data = (int *)malloc(arr->capacity * sizeof(int));
}

// Add an element to the end of 1D array
void pushBackIntArray(struct IntArray *arr, int val) {
    // Double capacity if needed
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        int *newData = (int *)realloc(arr->data, arr->capacity * sizeof(int));
        arr->data = newData;
    }
    arr->data[arr->size++] = val;  // Add value and increment size
}

// Remove last element from 1D array
void popBackIntArray(struct IntArray *arr) {
    if (arr->size > 0) {
        arr->size--;  // Simply decrement size (no memory deallocation)
    }
}

// Free memory allocated for 1D array
void freeIntArray(struct IntArray *arr) {
    if (arr->data) {
        free(arr->data);
        arr->data = NULL;
    }
    arr->size = 0;
    arr->capacity = 0;
}

// Initialize a 2D dynamic array
void initIntArray2D(struct IntArray2D *arr) {
    arr->capacity = 16;  // Initial capacity
    arr->size = 0;       // Empty array
    arr->data = (int **)malloc(arr->capacity * sizeof(int *));
    arr->cols = (int *)malloc(arr->capacity * sizeof(int));
}

// Add a copy of 1D array to 2D array
void pushBackIntArray2D(struct IntArray2D *arr, const struct IntArray *src) {
    // Double capacity if needed
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        int **newData = (int **)realloc(arr->data, arr->capacity * sizeof(int *));
        int *newCols = (int *)realloc(arr->cols, arr->capacity * sizeof(int));
        arr->data = newData;
        arr->cols = newCols;
    }
    
    // Allocate memory for new row and copy data
    arr->data[arr->size] = (int *)malloc(src->size * sizeof(int));    
    arr->cols[arr->size] = src->size;  // Store row length
    
    // Copy elements from source array
    for (int i = 0; i < src->size; i++) {
        arr->data[arr->size][i] = src->data[i];
    }
    arr->size++;  // Increment number of rows
}

// Free memory allocated for 2D array
void freeIntArray2D(struct IntArray2D *arr) {
    if (arr->data) {
        for (int i = 0; i < arr->size; i++) {
            if (arr->data[i]) {
                free(arr->data[i]);
                arr->data[i] = NULL;
            }
        }
        free(arr->data);
        arr->data = NULL;
    }
    if (arr->cols) {
        free(arr->cols);
        arr->cols = NULL;
    }
    arr->size = 0;
    arr->capacity = 0;
}

// Global variables (to simulate C++ class member variables)
struct IntArray2D ans;          // Stores all valid paths
struct IntArray currentPath;    // Stores current traversal path

// Depth-First Search to find all root-to-leaf paths with target sum
void dfs(struct TreeNode* root, int currentSum, int targetSum) {
    // Base case: null node
    if (!root) {
        return;
    }
    
    // Add current node's value to path and sum
    currentSum += root->val;
    pushBackIntArray(&currentPath, root->val);
    
    // Check if we reached a leaf node with target sum
    if (currentSum == targetSum && !root->left && !root->right) {
        // Found a valid path, add to results
        pushBackIntArray2D(&ans, &currentPath);
    }
    
    // Recursively traverse left and right subtrees
    dfs(root->left, currentSum, targetSum);
    dfs(root->right, currentSum, targetSum);
    
    // Backtrack: remove current node from path
    popBackIntArray(&currentPath);
}

/**
 * Find all root-to-leaf paths where each path's sum equals targetSum
 * 
 * @param root         - Pointer to the root of binary tree
 * @param targetSum    - Target sum to achieve
 * @param returnSize   - Output parameter: number of paths found
 * @param returnColumnSizes - Output parameter: array of path lengths
 * 
 * @return 2D array of paths. Each path is an array of integers.
 * 
 * Note: Both returned array and columnSizes array must be freed by caller.
 */
int** pathSum(struct TreeNode* root, int targetSum, 
              int* returnSize, int** returnColumnSizes) {
    // Initialize global data structures
    initIntArray2D(&ans);
    initIntArray(&currentPath);
    
    // Perform DFS traversal
    dfs(root, 0, targetSum);
    
    // Set output parameters
    *returnSize = ans.size;
    
    // Allocate and fill column sizes array
    *returnColumnSizes = (int *)malloc(ans.size * sizeof(int));
    
    for (int i = 0; i < ans.size; i++) {
        (*returnColumnSizes)[i] = ans.cols[i];
    }
    
    // Allocate result array and copy data
    int** result = (int **)malloc(ans.size * sizeof(int *));

    for (int i = 0; i < ans.size; i++) {
        result[i] = (int *)malloc(ans.cols[i] * sizeof(int));        
        // Copy path data
        for (int j = 0; j < ans.cols[i]; j++) {
            result[i][j] = ans.data[i][j];
        }
    }
    
    // Clean up temporary data structures
    freeIntArray2D(&ans);
    freeIntArray(&currentPath);
    
    return result;
}