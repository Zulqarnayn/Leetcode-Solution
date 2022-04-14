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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        
        while(root != nullptr) {
            if(root->left != nullptr) { 
                TreeNode* left = root->left;
                
                while(left->right != nullptr) left = left->right;
                
                left->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            
            root = root->right;
        }
    }
};