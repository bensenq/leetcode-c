// Function to compute the GCD using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the GCD of the smallest and largest numbers in the array
int findGCD(int* nums, int numsSize) {
    int minNum = nums[0];
    int maxNum = nums[0];

    // Find the smallest and largest numbers in the array
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minNum) {
            minNum = nums[i];
        }
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }

    // Compute the GCD of the smallest and largest numbers
    return gcd(minNum, maxNum);
}