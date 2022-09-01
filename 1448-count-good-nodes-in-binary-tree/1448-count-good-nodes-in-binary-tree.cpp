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
    int goodNodeCount = 0;
public:
    
    void findGoodNodes(TreeNode* root, int maxSoFar) {
        if(!root) return;
        
        if(root->val >= maxSoFar) {
            goodNodeCount++;
        }
        
        int newMax = maxSoFar < root->val ? root->val : maxSoFar;
        
        findGoodNodes(root->left, newMax);
        findGoodNodes(root->right, newMax);
    }
    
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        findGoodNodes(root, root->val);
        return goodNodeCount;
    }
};