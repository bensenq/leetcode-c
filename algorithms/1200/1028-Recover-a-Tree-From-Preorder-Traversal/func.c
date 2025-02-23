/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 typedef struct TreeNode TreeNode;

 TreeNode* recoverFromPreorderCore(char* traversal, int* index, int depth, int *latestdepth) {
     if (traversal[*index] == 0) return 0;
     int d = 0;
     if (*latestdepth == -1) {
         int d = 0;
         while(traversal[*index+d] == '-') d++;
         *index += d;
         *latestdepth = d;
     }
 
     if (*latestdepth == depth+1) {
         TreeNode* node = calloc(sizeof(TreeNode), 1);
         int val = 0;
         while(isdigit(traversal[*index])) {
             val = val * 10 + (traversal[*index] - '0');
             (*index)++;
         }
         node->val = val;
         *latestdepth = -1;    //latestdepth used
         node->left = recoverFromPreorderCore(traversal, index, depth+1, latestdepth);
         if (node->left) 
             node->right = recoverFromPreorderCore(traversal, index, depth+1, latestdepth);
         return node;
     }
     return 0;
 }
 
 TreeNode* recoverFromPreorder(char* traversal) {
     int index = 0;
     int lastdepth = 0;
     return recoverFromPreorderCore(traversal, &index, -1, &lastdepth);
 }