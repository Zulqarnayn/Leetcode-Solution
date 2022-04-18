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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> inorderList;
        int lastAns = 0;
        
        while(root != nullptr || inorderList.size() > 0) {
            while(root != nullptr) {
                inorderList.push(root);
                root = root->left;
            }
            
            root = inorderList.top();
            inorderList.pop();
            k--;
            
            if(!k) break;
            root = root->right;
        }
        
        return root->val;
    }
};