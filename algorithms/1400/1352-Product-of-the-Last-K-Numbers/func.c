typedef struct {
    int *lenProduct;
    int *reversedProduct;
    int count;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *obj = malloc(sizeof(ProductOfNumbers));
    obj->lenProduct = malloc(sizeof(int) * 40000);
    obj->reversedProduct = malloc(sizeof(int) * 40000);
    obj->reversedProduct[0] = 1;
    obj->lenProduct[0] = 0;
    obj->count = 1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if (num != 0) {
        obj->reversedProduct[obj->count] = obj->reversedProduct[obj->count-1]*num;
        obj->lenProduct[obj->count] = obj->lenProduct[obj->count-1] + 1;
    } else {
        obj->reversedProduct[obj->count] = 1;
        obj->lenProduct[obj->count] = 0;
    }
    obj->count++;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if (obj->lenProduct[obj->count-1] < k) return 0;
    int productAll = obj->reversedProduct[obj->count-1];
    int productBeforeLastK = obj->reversedProduct[obj->count-1-k];
    return  productAll/productBeforeLastK;
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj->reversedProduct);
    free(obj->lenProduct);
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/