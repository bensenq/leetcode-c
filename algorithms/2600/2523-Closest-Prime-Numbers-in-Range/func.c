#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

// Sieve of Eratosthenes

int* closestPrimes(int left, int right, int* returnSize) {
    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;

    if (right < 2) {
        return ans;
    }

    bool* isPrime = (bool*)malloc((right + 1) * sizeof(bool));
    for (int i = 0; i <= right; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    // core of algo
    for (int i = 2; i <= sqrt(right); i++) {
        if (isPrime[i]) {
            
            for (int j = i * i; j <= right; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int prevPrime = -1;
    int minDiff = right - left + 1;

    for (int i = left; i <= right; i++) {
        if (isPrime[i]) {
            if (prevPrime != -1) {
                int diff = i - prevPrime;
                if (diff < minDiff) {
                    minDiff = diff;
                    ans[0] = prevPrime;
                    ans[1] = i;
                    if (minDiff == 1) break;
                }
            }
            prevPrime = i;
        }
    }

    free(isPrime);
    return ans;
}