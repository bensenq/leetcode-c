/* struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
	if (t2 == NULL && t1 == NULL) {
		return NULL;
	}
	else {
		struct TreeNode * mergedtree = malloc(sizeof(struct TreeNode));  
		mergedtree->val = (t1?t1->val:0) + (t2?t2->val:0);
		mergedtree->left = mergeTrees(t1?t1->left:NULL, t2?t2->left:NULL);
		mergedtree->right = mergeTrees(t1?t1->right:NULL, t2?t2->right:NULL);
		return mergedtree;
	}
}
