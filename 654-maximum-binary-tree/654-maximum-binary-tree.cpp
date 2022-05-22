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
typedef pair<TreeNode*, int> pii;
class Solution {
public:
    pii findTreeNodeAndIndex(vector<int>& nums, int start, int end) {
        if(start > end) return {nullptr, -1};
        
        int mx = nums[start], mxIdx = start;
        
        for(int idx = start + 1; idx <= end; idx++) {
            if(mx < nums[idx]) {
                mx = nums[idx];
                mxIdx = idx;
            }
        }
        
        TreeNode *node = new TreeNode(mx);
        return {node, mxIdx};
    }
    
    TreeNode* makeTree(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        
        pii next = findTreeNodeAndIndex(nums, start, end);
        TreeNode *dummy = next.first, *ref = dummy;
        
        if(start <= end - 1) {
           dummy->left = makeTree(nums, start, next.second - 1); 
        }
        
        if(start + 1 <= end) {
           dummy->right = makeTree(nums, next.second + 1, end); 
        }
        
        return ref;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        
        return makeTree(nums, start, end);
    }
};