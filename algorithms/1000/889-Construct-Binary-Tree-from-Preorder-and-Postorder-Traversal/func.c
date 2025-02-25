/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 typedef struct TreeNode TreeNode;

 TreeNode* constructFromPrePostCore(int* preorder, int size, int* position) {
     TreeNode *node = malloc(sizeof(TreeNode));
     node->val = preorder[0];
     node->left = 0;
     node->right = 0;
     int leftLen = !!(size > 1), rightLen = 0;
     if (leftLen > 0) {
         leftLen = 1;
         preorder++;
         while(leftLen+1 < size && position[preorder[0]] > position[preorder[leftLen]])leftLen++;
         node->left = constructFromPrePostCore(preorder, leftLen, position);
         rightLen = size - 1 - leftLen;
     }
     if (rightLen > 0) {
         preorder += leftLen;
         node->right = constructFromPrePostCore(preorder, rightLen, position);
     }
     return node;
 }
 
 struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize) {
     int n = preorderSize;
     int position[n+1];
     int i = 0;
     while(i < n) {
         position[postorder[i]] = i;
         i++;
     }
     return constructFromPrePostCore(preorder, n, position);
 }