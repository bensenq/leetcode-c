//Monotonic Decreasing Stack


typedef struct {
    int *price;
    short *span;
    int top;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner * obj = malloc(sizeof(StockSpanner));
    obj->price = malloc(sizeof(int *) * 10000);
    obj->span = malloc(sizeof(short *) * 10000);
    obj->top = 0;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int span = 1;
    while (obj->top != 0 && price >= obj->price[obj->top-1]) {
        span += obj->span[obj->top-1];
        obj->top--;
    }
    obj->price[obj->top] = price;
    obj->span[obj->top] = span;
    obj->top++;
    return span;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj->price);
    free(obj->span);
    free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/