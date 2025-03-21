//Adjacency List Graphs (Trees)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // For INT_MIN

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adj[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

void dfs(Node* adj[], int parent[], int current, int prev) {
    for (Node* temp = adj[current]; temp != NULL; temp = temp->next) {
        if (temp->dest != prev) {
            parent[temp->dest] = current;
            dfs(adj, parent, temp->dest, current);
        }
    }
}

void findBobPath(Node* adj[], int parent[], int bob, int path[], int n) {
    int current = bob;
    int dist = 0;
    while (current != -1) {
        path[current] = dist++;
        current = parent[current];
    }
}

int calculateIncome(Node* adj[], int amount[], int parent[], int node, int bobPath[], int aliceDist) {
    // Calculate the income for the current node
    int aliceIncome = 0;
    if (bobPath[node] == aliceDist) {
        aliceIncome = amount[node] / 2;  // Alice and Bob arrive at the node simultaneously, split the income
    } else if (bobPath[node] == -1 || bobPath[node] > aliceDist) {
        aliceIncome = amount[node];  // Bob has not visited or Alice arrives first
    } else {
        aliceIncome = 0;  // Bob has already visited, no income for Alice
    }

    // Check if the current node is a leaf node
    int isLeaf = 1;  // Assume the current node is a leaf node by default
    int maxChildIncome = INT_MIN;  // Initialize to the smallest possible value
    for (Node* temp = adj[node]; temp != NULL; temp = temp->next) {
        if (temp->dest != parent[node]) {  // Avoid backtracking to the parent node
            isLeaf = 0;  // The current node has children, so it is not a leaf node
            int childIncome = calculateIncome(adj, amount, parent, temp->dest, bobPath, aliceDist + 1);
            if (childIncome > maxChildIncome) {
                maxChildIncome = childIncome;  // Update the maximum income from children
            }
        }
    }

    // If the current node is a leaf node, return its income
    if (isLeaf) {
        return aliceIncome;
    } else {
        return aliceIncome + maxChildIncome;  // Return the sum of the current node's income and the maximum child income
    }
}

int mostProfitablePath(int** edges, int edgesSize, int* edgesColSize, int bob, int* amount, int amountSize) {
    int n = amountSize;
    Node* adj[n];
    for (int i = 0; i < n; ++i) adj[i] = NULL;

    for (int i = 0; i < edgesSize; i++) {
        addEdge(adj, edges[i][0], edges[i][1]);
        addEdge(adj, edges[i][1], edges[i][0]);
    }

    int* parent = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) parent[i] = -1;
    dfs(adj, parent, 0, -1);

    int* bobPath = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) bobPath[i] = -1;
    findBobPath(adj, parent, bob, bobPath, n);

    int maxIncome = calculateIncome(adj, amount, parent, 0, bobPath, 0);

    free(parent);
    free(bobPath);
    return maxIncome;
}