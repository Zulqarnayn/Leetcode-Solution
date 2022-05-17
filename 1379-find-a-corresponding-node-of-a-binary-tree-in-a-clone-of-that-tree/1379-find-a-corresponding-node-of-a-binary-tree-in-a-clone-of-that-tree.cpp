/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == target) {
            return cloned;
        }
        
        TreeNode *t1 = nullptr, *t2 = nullptr;
        
        if(original->left && cloned->left) t1 = getTargetCopy(original->left, cloned->left, target);
        if(original->right && cloned->right) t2 = getTargetCopy(original->right, cloned->right, target);
        
        return t1 != nullptr ? t1 : t2;
    }
};