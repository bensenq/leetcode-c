bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (n == 0) return true;
    int empty = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if((i > 0 && flowerbed[i-1] == 0 || i == 0) 
            && (i < flowerbedSize - 1 && flowerbed[i+1] == 0 || i == flowerbedSize - 1) 
            && flowerbed[i] == 0) {
            n--;
            if (n == 0) return true;
            flowerbed[i] = 1;
            i += 1;
        }    
    }
    return false;
}