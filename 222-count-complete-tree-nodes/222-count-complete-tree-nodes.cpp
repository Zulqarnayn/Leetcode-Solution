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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> nodeQ;
        
        nodeQ.push(root);
        int count = 1;
        
        while(!nodeQ.empty()) {
            int size = nodeQ.size();
            while(size--) {
                TreeNode* top = nodeQ.front(); nodeQ.pop();
                if(top->left) {
                    nodeQ.push(top->left);
                    count++;
                }
                if(top->right) {
                    nodeQ.push(top->right);
                    count++;
                }
            }
        }
        
        return count;
    }
};