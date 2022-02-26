int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

// 2-d array for hashtable
#define BUCKETS 10000
#define BUCKET_SIZE ((4000000000) / BUCKETS)

struct node
{
	unsigned char index1;
	unsigned char index2;
	struct node *next;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
	int ***hashtable = calloc(BUCKETS + 1, sizeof(int **));
	int i, j;
	int buffSize = numsSize;
	int **result = malloc(sizeof(int *) * buffSize);
	int len = 0;

	// sort
	qsort(nums, numsSize, sizeof(int), compare);

	// construct hashtable
	for (i = 0; i < numsSize - 1; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			int sum = nums[i] + nums[j];
			int hash = ((long long)sum + 2000000000) / BUCKET_SIZE;
			int offset = ((long long)sum + 2000000000) % BUCKET_SIZE;
			struct node *n = malloc(sizeof(struct node));
			if (hashtable[hash] == 0)
			{
				hashtable[hash] = calloc(BUCKET_SIZE, sizeof(struct node *));
			}
			n->next = 0;
			n->index1 = i;
			n->index2 = j;
			if (hashtable[hash][offset] == 0)
			{
				hashtable[hash][offset] = (int *)n;
			}
			else
			{
				struct node *tmp = (struct node *)hashtable[hash][offset];
				int x;
				while (tmp->next != 0)
				{
					if (i == tmp->index1)
						break;
					if (nums[i] == nums[tmp->index1]) {
                        x++;
                        if (x == 3)
                            break;
                    }
					tmp = tmp->next;
				}
				if (tmp->next == 0)
					tmp->next = n;
			}
		}
	}

	// searching
	for (i = 0; i < numsSize - 1; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			int sum = nums[i] + nums[j];
			int t = target - sum;
			int hash = ((long long)t + 2000000000) / BUCKET_SIZE;
			int offset = ((long long)t + 2000000000) % BUCKET_SIZE;
			struct node *tmp;
			if (hashtable[hash] == 0 || hashtable[hash][offset] == 0)
				continue;
			tmp = (struct node *)hashtable[hash][offset];
			while (tmp != 0)
			{
				if (j < tmp->index1)
				{
					/* check redundancy */
					int k;
					for (k = 0; k < len; k++)
					{
						if (result[k][0] == nums[i] &&
							result[k][1] == nums[j] &&
							result[k][2] == nums[tmp->index1] &&
							result[k][3] == nums[tmp->index2])
							break;
					}
					/* not found */
					if (k == len)
					{
						if (len == buffSize)
						{
							buffSize *= 2;
							result = realloc(result, sizeof(int *) * buffSize);
						}
						result[len] = malloc(sizeof(int) * 4);
						result[len][0] = nums[i];
						result[len][1] = nums[j];
						result[len][2] = nums[tmp->index1];
						result[len][3] = nums[tmp->index2];
						len++;
					}
				}
				tmp = tmp->next;
			}
		}
	}
	*returnSize = len;
	*returnColumnSizes = malloc(sizeof(int) * len);
	for (i = 0; i < len; i++)
		(*returnColumnSizes)[i] = 4;

	// todo: free alloced hashtable memory
	return result;
}

int main(void)
{
	//    int test[] = {0,1,5,0,1,5,5,-4};
	//int test[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	//int test[] = {1,0,-1,0,-2,2};
	int test[] = {2,2,2,2,2};
	int size;
	int *returnSize;
	fourSum(test, sizeof(test) / 4, 8, &size, &returnSize);
	return 0;
}
