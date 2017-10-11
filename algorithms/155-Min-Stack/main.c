typedef struct {
	int *stack;
	int top;
	int *min;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
	MinStack *obj = malloc(sizeof(MinStack));
	obj->stack = malloc(sizeof(int)*maxSize);
	obj->min = malloc(sizeof(int)*maxSize);
	obj->top = -1;
	return obj;
}

void minStackPush(MinStack* obj, int x) {
	obj->top++;
	obj->stack[obj->top] = x;
	if(obj->top == 0) {
		obj->min[0] = x;
	} else {
		if (x < obj->min[obj->top-1])
			obj->min[obj->top] = x;
		else
			obj->min[obj->top] = obj->min[obj->top-1];
	}
}

void minStackPop(MinStack* obj) {
	obj->top--;
}

int minStackTop(MinStack* obj) {
	return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
	return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
	free(obj->stack);
	free(obj->min);
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
