class Solution {
public:
    bool find(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return nums[lo] == target;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int idx = 0; idx < matrix.size(); idx++) {
            if(find(matrix[idx], target)) { return true; }
        }
        return false;
    }
};