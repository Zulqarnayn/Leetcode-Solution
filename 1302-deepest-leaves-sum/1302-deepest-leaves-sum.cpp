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
    
    int calculateMaxHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int left = calculateMaxHeight(root->left);
        int right = calculateMaxHeight(root->right);
        
        return max(left, right) + 1;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int maxHeight = calculateMaxHeight(root);
        
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
        int sum = 0;
        
        while(!q.empty()) {
            int size = q.size();
            height++;
            
            while(size--) {
                TreeNode* front = q.front(); q.pop();
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                
                if(height == maxHeight) {
                    sum += front->val;
                }
            }
        }
        
        return sum;
    }
};