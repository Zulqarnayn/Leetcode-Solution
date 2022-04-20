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
    
    int calculateSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        
        if(root->left) root->left->val = root->val * 10 + root->left->val;
        if(root->right) root->right->val = root->val * 10 + root->right->val;
        
        return calculateSum(root->left) + calculateSum(root->right);
    }
    
    int sumNumbers(TreeNode* root) {
        return calculateSum(root);
    }
};