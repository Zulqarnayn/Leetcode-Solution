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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        stack<TreeNode*> nodeStk;
        TreeNode* curr = root;
        
        while(curr != nullptr || nodeStk.size() > 0) {
            while(curr != nullptr) {
                nodeStk.push(curr);
                curr = curr->left;
            }
            
            curr = nodeStk.top();
            nodeStk.pop();
            if(curr) {
                nodes.push_back(curr);
            }
            
            curr = curr->right;
        }
        
        int i = 0, j = nodes.size() - 1;
        
        for(i = 0; i < nodes.size() - 1; i++) {
            if(nodes[i]->val > nodes[i+1]->val) break;
        }
        
        for(j = nodes.size() - 1; j > 0; j--) {
            if(nodes[j]->val < nodes[j-1]->val) break;
        }
        
        swap(nodes[i]->val, nodes[j]->val);
    }
};