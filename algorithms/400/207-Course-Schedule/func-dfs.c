//DFS: cycle detection
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

// DFS 
bool acyclicDFS(Graph* graph, bool* todo, bool* done, int node) {
    if (todo[node]) {
        return false;
    }
    
    if (done[node]) {
        return true;
    }
    
    todo[node] = true;
    done[node] = true;
    
    Node* current = graph->adjList[node];
    while (current != NULL) {
        if (!acyclicDFS(graph, todo, done, current->vertex)) {
            return false;
        }
        current = current->next;
    }
    
    todo[node] = false;
    return true;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    Graph* graph = buildGraph(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize);
    
    bool* todo = (bool*)calloc(numCourses, sizeof(bool));
    bool* done = (bool*)calloc(numCourses, sizeof(bool));
    
    bool result = true;
    for (int i = 0; i < numCourses; i++) {
        if (!done[i]) {
            if (!acyclicDFS(graph, todo, done, i)) {           
                result = false;
                break;
            }
        }
    }
    
    free(todo);
    free(done);
    freeGraph(graph);
    return result;
}