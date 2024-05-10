/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> path;
    
    void dfs(TreeNode* root, int current, int target) {
        if(!root) {
            return;
        }
        
        current += root->val;
        path.push_back(root->val);
        
	// When we reach at leaf node, we have to check if current sum is equal to target
        if(current == target && !root->left && !root->right) {
            ans.push_back(path);
        }    
        
        dfs(root->left, current, target);
        dfs(root->right, current, target);
        
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, targetSum);
        return ans;
    }
};
