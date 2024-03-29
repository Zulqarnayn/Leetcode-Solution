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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        
        vector<int> result;
        result.push_back(root->val);
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int idx = 0; idx < size; idx++) {
                TreeNode* top = q.front(); q.pop();
                
                if(top->right) {
                    q.push(top->right);
                }
                if(top->left) {
                    q.push(top->left);
                }
            }
            
            if(!q.empty()) {
                result.push_back(q.front()->val);
            }
        }
        
        return result;
    }
};