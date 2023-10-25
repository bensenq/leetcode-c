// treat as a tree growing down: The left child remains the same as 
// the parent, and the right child has the opposite value.

int kthGrammar(int n, int k){
    int parent = 0;
    while (n > 1) {
        int half = 1 << (n-2);
        if (k > half) {    //right
            if (parent == 0) parent = 1;
            else parent = 0;
            k -= half;
        }
        n--;
    }
    return  parent;
}