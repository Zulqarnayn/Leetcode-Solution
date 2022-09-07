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
    void constructStr(TreeNode* root, string &s) {
        if(!root) {
            return;
        }
        
        s += to_string(root->val);
        if(root->left) {
            s += "(";
            constructStr(root->left, s);
            s += ")";
        }
        
        if(root->right) {
            if(!root->left) s += "()";
            s += "(";
            constructStr(root->right, s);
            s += ")";
        }
        
    }
    
    string tree2str(TreeNode* root) {
        string result = "";
        constructStr(root, result);
        return result;
    }
};