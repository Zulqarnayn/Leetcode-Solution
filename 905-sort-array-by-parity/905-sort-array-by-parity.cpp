class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int positionToReplace = 0;
        
        for(int idx = 0; idx < nums.size(); idx++) {
            if(!(nums[idx] & 1)) {
                swap(nums[idx], nums[positionToReplace]);
                positionToReplace++;
            }
        }
        
        return nums;
    }
};