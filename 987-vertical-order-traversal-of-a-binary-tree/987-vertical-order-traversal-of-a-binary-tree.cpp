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
    pair<pair<int, int>, int> sortedPairs[1001];
    int idx = 0;
public:
    void traverseAndStore(TreeNode* root, int left, int right) {
        if(!root) return;
        
        sortedPairs[idx++] = {{left, right}, root->val};
        
        traverseAndStore(root->left, left - 1, right + 1);
        traverseAndStore(root->right, left + 1, right + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverseAndStore(root, 0, 0);
        
        sort(sortedPairs, sortedPairs + idx);
        vector<vector<int>> result;
        
        int currentLeft = sortedPairs[0].first.first, vIndex = 0;
        result.push_back({});
        
        for(int i = 0; i < idx; i++) {
            if(sortedPairs[i].first.first != currentLeft) {
                vIndex++;
                currentLeft = sortedPairs[i].first.first;
                result.push_back({});
            }
            
            result[vIndex].push_back(sortedPairs[i].second);
        }
    
        return result;
    }
};