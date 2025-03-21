/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 #define max(a,b) ((a) > (b) ? (a) : (b))

 typedef struct {
     bool *nodes;
     int capicity;
 } FindElements;
 
 int getHeight(struct TreeNode* root) {
     if (root == 0) return 0;
     return max(getHeight(root->left), getHeight(root->right)) + 1;
 }
 
 void initNodesArray(struct TreeNode* root, int index, bool *nodes) {
     nodes[index] = true;
     if (root->left) initNodesArray(root->left, index*2+1, nodes);
     if (root->right) initNodesArray(root->right, index*2+2, nodes);
 }
 
 FindElements* findElementsCreate(struct TreeNode* root) {
     int height = getHeight(root);
     int capicity = (1<<height) - 1;
     FindElements *obj = malloc(sizeof(FindElements));
     obj->capicity = capicity;
     obj->nodes = calloc(sizeof(bool), capicity);    //init to false
     initNodesArray(root, 0, obj->nodes);     //init nodes in tree to true
     return obj;
 }
 
 bool findElementsFind(FindElements* obj, int target) {
     if(target >= obj->capicity) return false;
     return obj->nodes[target];
 }
 
 void findElementsFree(FindElements* obj) {
     free(obj->nodes);
     free(obj);
 }
 
 /**
  * Your FindElements struct will be instantiated and called as such:
  * FindElements* obj = findElementsCreate(root);
  * bool param_1 = findElementsFind(obj, target);
  
  * findElementsFree(obj);
 */