int fib(int n){
    if(n == 0 || n == 1)
        return n;
    
    int fn1 = 1, fn2 = 0, fn;
    int i = 2;
    while(i <= n) {
        fn = fn1 + fn2;
        fn2 = fn1;
        fn1 = fn;
        i++;
    }
    return fn1;
}