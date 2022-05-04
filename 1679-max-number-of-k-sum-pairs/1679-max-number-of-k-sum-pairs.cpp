class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        /*
        Approach 1: sort & 2 pointer
        ----------------------------
        
        sort(nums.begin(), nums.end());
        
        int size = nums.size(), start = 0, end = size - 1, count = 0;
        
        while(start < end) {
            int sum = nums[start] + nums[end];
            
            if(sum > k) {
                end--;
            } else if(sum < k) {
                start++;
            } else {
                count++;
                start++;
                end--;
            }
        }
        
        return count;
        */
        
        // Approach 2: frequency count
        // ----------------------------
        
        unordered_map<int, int> freq;
        int count = 0;
        
        for(auto num: nums) {
            int rem = k - num;
            if(freq[rem] > 0) {
                count++;
                freq[rem]--;
            } else {
                freq[num]++;
            }
        }
        
        return count;
    }
};