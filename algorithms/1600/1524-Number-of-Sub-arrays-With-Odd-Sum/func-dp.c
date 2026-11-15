// dp
int numOfSubarrays(int* arr, int arrSize) {
    int adjOdd = arr[0] % 2, adjEven = !adjOdd;
    int nonAdjOdd = 0, nonAdjEven = 0;
    int newAdjOdd, newAdjEven;
    int i = 1;
    while(i < arrSize) {
        if(arr[i] % 2 == 0) {   //even
            newAdjOdd = adjOdd;
            newAdjEven = adjEven+1;
        } else {                //odd
            newAdjOdd = adjEven+1;
            newAdjEven = adjOdd;
        }
        nonAdjOdd = (nonAdjOdd + adjOdd) % 1000000007;
        nonAdjEven = (nonAdjEven + adjEven) % 1000000007;
        adjOdd = newAdjOdd;
        adjEven = newAdjEven;
        i++;
    }
    return (nonAdjOdd + adjOdd) % 1000000007;
}