typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node** adjList;
    int numCourses;
} Graph;

Graph* buildGraph(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numCourses = numCourses;
    graph->adjList = (Node**)malloc(numCourses * sizeof(Node*));
    
    for (int i = 0; i < numCourses; i++) {
        graph->adjList[i] = NULL;
    }
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int from = prerequisites[i][1];
        int to = prerequisites[i][0];
        
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = to;
        newNode->next = graph->adjList[from];
        graph->adjList[from] = newNode;
    }
    
    return graph;
}

int* computeIndegrees(Graph* graph) {
    int* degrees = (int*)calloc(graph->numCourses, sizeof(int));
    
    for (int i = 0; i < graph->numCourses; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            degrees[current->vertex]++;
            current = current->next;
        }
    }
    
    return degrees;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numCourses; i++) {
        Node* current = graph->adjList[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adjList);
    free(graph);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {

    Graph* graph = buildGraph(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize);
    int* degrees = computeIndegrees(graph);

    *returnSize = 0;
    int* result = (int*)malloc(numCourses * sizeof(int));
    if (result == NULL) {
        free(degrees);
        freeGraph(graph);
        *returnSize = 0;
        return NULL;
    }
    
    int resultIndex = 0;
    
    for (int i = 0; i < numCourses; i++) {
        int j = 0;
        for (; j < numCourses; j++) {
            if (degrees[j] == 0) {
                break;
            }
        }
        
        if (j == numCourses) {
            free(degrees);
            freeGraph(graph);
            free(result);
            *returnSize = 0;
            return NULL;
        }
        
        result[resultIndex++] = j;
        
        degrees[j] = -1;
        
        Node* current = graph->adjList[j];
        while (current != NULL) {
            degrees[current->vertex]--;
            current = current->next;
        }
    }
    
    *returnSize = numCourses;
    
    free(degrees);
    freeGraph(graph);
    
    return result;
}