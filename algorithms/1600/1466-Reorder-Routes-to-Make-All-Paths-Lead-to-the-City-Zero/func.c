struct adjListNode {
    int node;
    int direction;
    struct adjListNode *next;
};

struct nodeAdj {
    struct adjListNode *head;
    struct adjListNode *tail;
};

void append(struct nodeAdj* node, int adjnode, int direction) {
    struct adjListNode *adjNode = malloc(sizeof(struct adjListNode));
    adjNode->node = adjnode;
    adjNode->direction = direction;
    adjNode->next = 0;
    if (node->head == 0) {
        node->head = adjNode;
        node->tail = adjNode;
    } else {
        node->tail->next = adjNode;
        node->tail = adjNode;
    }
}

void dfs(int index, struct nodeAdj* nodes, int *count, char *visited) {
    visited[index] = 1;
    struct adjListNode *t = nodes[index].head;
    while(t) {
        if (!visited[t->node]) {
            if (t->direction == 1) *count += 1;
            dfs(t->node, nodes, count, visited);
        }
        t = t->next;
    }
}

int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    int size = connectionsSize;
    char *visited = calloc(1, n);
    int count = 0;
    struct nodeAdj* nodes = calloc(sizeof(struct nodeAdj), n);
    for (int i = 0; i < size; i++) {
        int start = connections[i][0];
        int end = connections[i][1];
        append(&nodes[start], end, 1);
        append(&nodes[end], start, -1);
    }

    dfs(0, nodes, &count, visited);
    
    /* cleanup code */
    for (int i = 0; i < n; i++) {
        struct adjListNode *t = nodes[i].head, *p;
        while (t) {
            p = t->next;
            free(t);
            t = p;
        }
    }
    free(nodes);
    free(visited);
    return count;
}