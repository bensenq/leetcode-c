// 2-d array for hashtable
#define BUCKETS 10000
#define BUCKET_SIZE ((2000000000)/BUCKETS)

struct node {
    char index1;
    char index2;
    struct node *next;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int ***hashtable = calloc(BUCKETS, sizeof(int **));
	int i, j;
    int maxsize = numsSize*(numsSize-1)*(numsSize-2)*(numsSize-3);
	int **result = malloc(sizeof(int *)*maxsize);
    int len = 0;

    //construct hashtable
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i+1; j < numsSize; j++) {
            int sum = nums[i] + nums[j];
            int hash = (sum + 1000000000) / BUCKET_SIZE;
            int offset = (sum + 1000000000) % BUCKET_SIZE;
            struct node *n = malloc(sizeof(struct node));
            if (hashtable[hash] == 0) {
                hashtable[hash] = calloc(BUCKET_SIZE, sizeof(struct node*));
            }
            n->next = 0;
            n->index1 = i;
            n->index2 = j;
            if(hashtable[hash][offset] == 0) {
                hashtable[hash][offset] = n;               
            } else {
                struct node *tmp = hashtable[hash][offset];
                while(tmp->next != 0) {
                    tmp = tmp->next;
                }
                tmp->next = n;
            }
        }
    }

    //searching
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i+1; j < numsSize; j++) {
            int sum = nums[i] + nums[j];
            int target = -sum;
            int hash = (target + 1000000000) / BUCKET_SIZE;
            int offset = (target + 1000000000) % BUCKET_SIZE;
            struct node *tmp;
            if (hashtable[hash] == 0 || hashtable[hash][offset] == 0)
                continue;
            tmp = (struct node *)hashtable[hash][offset];
            while(tmp != 0) {
                if (tmp->index1 > j) {
                    result[len] = malloc(sizeof(int) * 4);
                    result[len][0] = i;
                    result[len][1] = j;
                    result[len][2] = tmp->index1;
                    result[len][3] = tmp->index2;
                    len++;
                }
                tmp = tmp->next;
            }
        }
    }
    *returnSize = len;
    *returnColumnSizes = malloc(sizeof(int) * len);
    for (i = 0; i < len; i++)
        (*returnColumnSizes)[len] = 4;

    //todo: free alloced hashtable memory
    return result;
}

int main() {
    int test[] = {1,0,-1,0,-2,2};
    int size;
    int *returnSize;
    fourSum(test, 6, 0, &size, &returnSize);
    return 0;
}