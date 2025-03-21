bool inSet (char *var, char **set, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(var, set[i]) == 0)
            return true;
    }
    return false;
}

double dfs(char *first, char *second, char*** equations, int equationsSize, double* values, char *visited) {
    if (strcmp(first, second) == 0) {
        return 1.0;
    } 
    for (int i = 0; i < equationsSize; i++) {
        if (strcmp(first, equations[i][0]) == 0 && strcmp(second, equations[i][1]) == 0)
            return values[i];
        if (strcmp(first, equations[i][1]) == 0 && strcmp(second, equations[i][0]) == 0)
            return 1/values[i];
    }

    for (int i = 0; i < equationsSize; i++) {
        if (visited[i] == 0) {
            if (strcmp(first, equations[i][0]) == 0) {
                visited[i] = 1;
                double ans = dfs(equations[i][1], second, equations, equationsSize, values, visited);
                if (ans != -1.0) return values[i]*ans;
            } else if (strcmp(first, equations[i][1]) == 0) {
                visited[i] = 1;
                double ans = dfs(equations[i][0], second, equations, equationsSize, values, visited);
                if (ans != -1.0) return ans/values[i];
            }
        }
    }
    return -1.0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* calcEquation(char*** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char*** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    double *ans = malloc(sizeof(double) * queriesSize);
    char ** variables = malloc(sizeof(char *) * 40);
    int size = 0;
    for (int i = 0; i < equationsSize; i++) {
        if (!inSet(equations[i][0], variables, size)) {
            variables[size] = equations[i][0];
            size++;
        }
        if (!inSet(equations[i][1], variables, size)) {
            variables[size] = equations[i][1];
            size++;
        }
    }
    
    for (int i = 0; i < queriesSize; i++) {
        if (!inSet(queries[i][0], variables, size) || !inSet(queries[i][1], variables, size)) {
            ans[i] = -1.0;
        } else {
            char * visited = calloc(sizeof(char), equationsSize);
            ans[i] = dfs(queries[i][0], queries[i][1], equations, equationsSize, values, visited);
            free(visited);
        }
    }
    free(variables);
    *returnSize = queriesSize;
    return ans;
}