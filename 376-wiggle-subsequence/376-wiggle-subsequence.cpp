class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        bool toggle = false;
        int sz = nums.size();
        int neg = 0;
        int pos = 0;
        
        for(int i=1; i<sz; i++) {
            int diff = nums[i] - nums[i-1];
            if(diff > 0) {
                pos = neg + 1;
            } else if (diff < 0) {
                neg = pos + 1;
            }
        }
        return max(neg, pos) + 1;
    }
};