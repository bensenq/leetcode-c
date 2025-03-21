/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a, b) (a>b?a:b)

/* find longest Zigzag from root: depth first search
 * direction: 0 for left; 1 for right */
int longestZigZagInclude(struct TreeNode* root, int direction) {
    struct TreeNode *target;
    int depth = 0;
    target = direction ? root->right : root->left;
    while(target) {
        depth++;
        direction = direction ? 0 : 1;
        target = direction ? target->right : target->left;
    };
    return depth;
}

/* exclude `from` as already checked 
 * from: 0 for left， 1 for right  */
int longestZigZagCore(struct TreeNode* root, int from) {
    int ans = 0;
    int ret;
    if (from == 0) {
        if (root->right) {
            ret = longestZigZagCore(root->right, 1);
            ans = max(ans, ret);
        }
        if (root->left) {
            ret = longestZigZagInclude(root->left, 1) + 1;
            ans = max(ans, ret);
            ret = longestZigZagCore(root->left, 0);
            ans = max(ans, ret);
        } 
    
    } else {
        if (root->left) {
            ret = longestZigZagCore(root->left, 0);
            ans = max(ans, ret);
        } 
        if (root->right) {
            ret = longestZigZagInclude(root->right, 0) + 1;
            ans = max(ans, ret);
            ret = longestZigZagCore(root->right, 1);
            ans = max(ans, ret);            
        } 
    }
    return ans;
}

int longestZigZag(struct TreeNode* root) {
    int ret = 0;
    int ans = 0;
    if (root->left) { 
        ret = longestZigZagInclude(root->left, 1) + 1;
        ans = max(ans, ret);
        ret = longestZigZagCore(root->left, 0);
        ans = max(ans, ret);
    }

    if (root->right) {
        ret = longestZigZagInclude(root->right, 0) + 1;
        ans = max(ans, ret);
        ret = longestZigZagCore(root->right, 1);
        ans = max(ans, ret);        
    }

    return ans;
}