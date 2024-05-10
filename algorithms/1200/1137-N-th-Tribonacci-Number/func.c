int tribonacci(int n){
    if(n == 0) 
        return 0;
    if(n == 1 && n == 2) 
        return 1;
    
    int Tn0 = 0, Tn1 = 1, Tn2 = 1, Tn;
    int i = 3;
    while(i <= n) {
        Tn = Tn0 + Tn1 + Tn2;
        Tn0 = Tn1;
        Tn1 = Tn2;
        Tn2 = Tn;
        i++;
    }
    return Tn2;
}