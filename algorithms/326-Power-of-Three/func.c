/* 1162261467 is 3^19,  3^20 is bigger than int */
/* We can use this method to judge power of 2, 3, 5, 7, 11, ... since they are prime numbers. */
bool isPowerOfThree(int n){
    return ( n > 0) && (1162261467%n==0);
}