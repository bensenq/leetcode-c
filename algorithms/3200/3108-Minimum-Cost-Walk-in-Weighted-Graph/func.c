//Editorial Approach1: disjoint set union

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Find function to return the root (representative) of a node's component
int find(int node, int *parent) {
    // If the node is its own parent, it is the root of the component
    if (parent[node] == -1) return node;
    // Otherwise, recursively find the root and apply path compression
    return parent[node] = find(parent[node], parent);
}

// Union function to merge the components of two nodes
void Union(int node1, int node2, int *parent, int *depth) {
    int root1 = find(node1, parent);
    int root2 = find(node2, parent);

    // If the two nodes are already in the same component, do nothing
    if (root1 == root2) return;

    // Union by depth: ensure the root of the deeper tree becomes the parent
    if (depth[root1] < depth[root2]) {
        int t = root1;
        root1 = root2;
        root2 = t;
    }

    // Merge the two components by making root1 the parent of root2
    parent[root2] = root1;

    // If both components had the same depth, increase the depth of the new
    // root
    if (depth[root1] == depth[root2]) depth[root1]++;
}


int* minimumCost(int n, int** edges, int edgesSize, int* edgesColSize, int** query, int querySize, int* queryColSize, int* returnSize) {
    int *parent = malloc(sizeof(int) * n);
    int *depth = calloc(sizeof(int), n);
    unsigned int *componentCost = malloc(sizeof(unsigned int) * n);
    // Initialize the parent array with -1 as initially each node belongs to
    // its own component
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
    // All values are initially set to the number with only 1s in its binary
    // representation
    for (int i = 0; i < n; i++) {
        componentCost[i] = ~0U;
    }
    
    // Construct the connected components of the graph
    for (int i = 0; i < edgesSize; i++) {
        Union(edges[i][0], edges[i][1], parent, depth);
    }

    // Calculate the cost of each component by performing bitwise AND of all
    // edge weights in it
    for (int i = 0; i < edgesSize; i++) {
        int root = find(edges[i][0], parent);
        componentCost[root] &= edges[i][2];
    }
    
    int *answer = malloc(sizeof(int) * querySize);
    *returnSize = querySize;
    for (int i = 0; i < querySize; i++) {
        int start = query[i][0];
        int end = query[i][1];

        // If the two nodes are in different connected components, return -1
        if (find(start, parent) != find(end, parent)) {
            answer[i] = -1;
        } else {
            // Find the root of the edge's component
            int root = find(start, parent);
            // Return the precomputed cost of the component
            answer[i] = componentCost[root];
        }
    }
    free(parent);
    free(depth);
    free(componentCost);
    return answer;
}