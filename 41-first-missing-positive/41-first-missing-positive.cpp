class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
        for(int idx = 0; idx < size; idx++) {
            while(nums[idx] > 0 && nums[idx] <= size && nums[idx] != nums[nums[idx] - 1]) {
                swap(nums[nums[idx] - 1], nums[idx]);
            }
        }
        
        for(int idx = 0; idx < size; idx++) {
            if(nums[idx] != idx + 1) return idx + 1;
        }
        
        return size + 1;
    }
};
/*
[2, 1]
[1,2,0]
[3,4,-1,1]
[7,8,9,11,12]
[1, 1, 1, 2]
*/