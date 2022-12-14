

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void deleteTree(struct TreeNode* t) {
    if (t == 0) return;
    if (t->left != 0) {
        deleteTree(t->left);
    }

    if (t->right != 0) {
       deleteTree(t->right);
    }
    
    free(t);
}

struct TreeNode* copyTree(struct TreeNode* t, int shift) {
    if (t == 0) return 0;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = t->val + shift;
    if (t->left != 0) {
        root->left = copyTree(t->left, shift);
    } else {
        root->left = 0;
    }

    if (t->right != 0) {
        root->right = copyTree(t->right, shift);
    } else {
        root->right = 0;
    }

    return root;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** generateTrees(int n, int* returnSize){
    int i, j;
    int sizes[n+1];
    struct TreeNode** result;
    struct TreeNode** Trees[n+1];
    struct TreeNode* t;
    sizes[0] = 1;
    Trees[0] = malloc(sizeof(struct TreeNode*));
    Trees[0][0] = 0;

    sizes[1] = 1;
    Trees[1] = malloc(sizeof(struct TreeNode*));
    t = calloc(sizeof(struct TreeNode), 1);
    Trees[1][0] = t;
    t->val = 1;
    i = 2;
    while (i <= n) {
        int left, right;
        int initSize = sizes[i-1] * 2;
        sizes[i] = 0;
        Trees[i] = malloc(sizeof(struct TreeNode*) * initSize);
        for (left = i - 1; left >= 0; left--) {
            right = i - 1 - left;
            for (int k = 0; k < sizes[left]; k++) {
                for (int j = 0; j < sizes[right]; j++) {
                    t = calloc(sizeof(struct TreeNode), 1);
                    t->val = left + 1;
                    t->left = copyTree(Trees[left][k], 0);
                    t->right = copyTree(Trees[right][j], t->val);
                    if (sizes[i] == initSize) {
                        initSize *= 2;
                        Trees[i] = realloc(Trees[i], sizeof(struct TreeNode*) * initSize);
                    }
                    Trees[i][sizes[i]] = t;
                    sizes[i] += 1;
                }
            }
        }
        i++;
    }

    *returnSize = sizes[n];
    result = Trees[n];

    /* free memory */
    for (i = 0; i < n; i++) {
        for (j = 0; j < sizes[i]; j++) {
            deleteTree(Trees[i][j]);
        }
    }
    
    return result;
}


int main() {
    int size;
    generateTrees(3, &size);
    return 0;
}