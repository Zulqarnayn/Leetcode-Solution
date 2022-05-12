class Solution {
public:
    void calculate(vector<int>& nums, vector<int> &tempRes, vector<int> &visited, set<vector<int>>& resultSet) {
        if(tempRes.size() == nums.size()) {
            resultSet.insert(tempRes);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) continue;
            visited[i] = 1;
            tempRes.push_back(nums[i]);
            calculate(nums, tempRes, visited, resultSet);
            tempRes.pop_back();
            visited[i] = 0;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> resultSet;
        vector<int> tempRes, visited(nums.size(), 0);
        calculate(nums, tempRes, visited, resultSet);
        
        for(auto v: resultSet) {
            result.push_back(v);
        }
        
        return result;
        
    }
};