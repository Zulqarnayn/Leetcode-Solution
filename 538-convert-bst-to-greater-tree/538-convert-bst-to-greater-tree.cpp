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
    int sum = 0;
public:
    
    void inorderTraversal(TreeNode* root) {
        if(root == nullptr) return;
        
        inorderTraversal(root->right);
        sum += root->val;
        root->val = sum;
        inorderTraversal(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        inorderTraversal(root);
        return root;
    }
};