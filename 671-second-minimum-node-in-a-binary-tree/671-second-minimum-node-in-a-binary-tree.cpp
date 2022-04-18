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
    
    void inorderTraversal(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        
        vector<int> res;
        inorderTraversal(root, res);
        sort(res.begin(), res.end());
        
        if(res.size() == 0) return -1;
        
        int smallestElement = res[0];
        
        for(int i = 0; i < res.size(); i++) {
            cout << i << " " << res[i] << endl;
            if(res[i] > smallestElement) return res[i];
        }
        
        return -1;
    }
};