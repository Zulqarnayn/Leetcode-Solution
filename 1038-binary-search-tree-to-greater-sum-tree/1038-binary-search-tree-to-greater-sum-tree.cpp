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
    
    /*
        same as https://leetcode.com/problems/convert-bst-to-greater-tree/
    */
    
    void inorderTraversal(TreeNode* root, vector<int>& sortedArr) {
        if(root == nullptr) return;
        
        inorderTraversal(root->left, sortedArr);
        sortedArr.push_back(root->val);
        inorderTraversal(root->right, sortedArr);
    }
    
    void updateKeys(TreeNode* root, unordered_map<int, int>& cummSum) {
        if(root == nullptr) return;
        
        root->val = cummSum[root->val];
        updateKeys(root->left, cummSum);
        updateKeys(root->right, cummSum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> sortedArr;
        unordered_map<int, int> cummSum;
        
        inorderTraversal(root, sortedArr);
        int size = sortedArr.size();
        
        for(int idx = size - 1; idx >= 0; idx--) {
            if(idx == size - 1) cummSum[sortedArr[idx]] = sortedArr[idx];
            else {
               cummSum[sortedArr[idx]] = sortedArr[idx] + cummSum[sortedArr[idx + 1]];
            }
        }
        
        updateKeys(root, cummSum);
        
        return root;
    }
};