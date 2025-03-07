#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int* closestPrimes(int left, int right, int* returnSize) {
    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;

    int prevPrime = -1;
    int minDiff = right - left + 1;

    for (int i = left; i <= right; i++) {
        if (isPrime(i)) {
            if (prevPrime != -1) {
                int diff = i - prevPrime;
                if (diff < minDiff) {
                    minDiff = diff;
                    ans[0] = prevPrime;
                    ans[1] = i;
                }
            }
            prevPrime = i;
        }
    }

    return ans;
}