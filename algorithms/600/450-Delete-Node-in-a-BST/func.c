//ref: https://www.geeksforgeeks.org/deletion-in-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    // Base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
        return root;
    }

    // If key is same as root's key, then this is the node to be deleted
    // Node with only one child or no child
    if (root->left == NULL) {
        struct TreeNode* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct TreeNode* temp = root->left;
        free(root);
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    struct TreeNode* succParent = root;
    struct TreeNode* succ = root->right;
    while (succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
    }

    // Copy the inorder successor's content to this node
    root->val = succ->val;

    // Delete the inorder successor
    if (succParent->left == succ)
        succParent->left = succ->right;
    else
        succParent->right = succ->right;

    free(succ);
    return root;    
}