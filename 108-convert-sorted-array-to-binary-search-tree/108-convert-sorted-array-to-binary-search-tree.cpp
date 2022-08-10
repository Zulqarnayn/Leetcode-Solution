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
    // Mistakes I made:
    // I returned the number where start == end
    // also when I create tree element from root
    // i missed the right condition to mid, instead of mid + 1
    TreeNode* createBST(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;
        
        int mid = (right + left) / 2;
        
        TreeNode* result = new TreeNode(nums[mid]);
        
        result->left = createBST(nums, left, mid - 1);
        result->right = createBST(nums, mid + 1, right);
        
        return result;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        
        return createBST(nums, 0, nums.size() - 1);
    }
};