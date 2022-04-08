class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size(), result = 1000000, DIFF = 1000000;
        
        for(int idx = 0; idx < size - 2; idx++) {
            int val = nums[idx];
            int lo = idx + 1, hi = size - 1;
            
            while(lo < hi) {
                int sum = val + nums[lo] + nums[hi];
                int diff = abs(target - sum);
                
                if(diff < DIFF) {
                    DIFF = diff;
                    result = sum;
                }
                if(sum > target) {
                    hi--;
                } else {
                    lo++;
                }
            }
        }
        
        return result;
    }
};

/*
[-1,2,1,-4]
3
[0,0,0]
1
*/