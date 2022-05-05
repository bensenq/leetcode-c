int compare (const void * a, const void * b){
    int diffa = (*(int **)a)[1] - (*(int **)a)[0];
    int diffb = (*(int **)b)[1] - (*(int **)b)[0];
	return (diffb - diffa);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int sum = 0;
    int i = 0;
    qsort(costs, costsSize, sizeof(int*), compare);
    while (i < costsSize/2) {
        sum += costs[i++][0];
    }
    
    while (i < costsSize) {
        sum += costs[i++][1];
    }
    return sum;
}