class Solution {
public:
    
    void calculateCombination(int idx, int k, int sum, vector<int> &coins, vector<vector<int>> &res, vector<int> &current, vector<int> &visited) {
        if(idx == coins.size() || sum <= 0) {
            if(sum == 0 && current.size() == k) res.push_back(current);
            return;
        }
        
        for(int i = idx; i < coins.size(); i++) {
            if(visited[coins[i]]) continue;
            current.push_back(coins[i]);
            visited[coins[i]] = 1;
            calculateCombination(i + 1, k, sum - coins[i], coins, res, current, visited);
            visited[coins[i]] = 0;
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> coins = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, current, visited(10, 0);
        vector<vector<int>> result;
        calculateCombination(0, k, n, coins, result, current, visited);
        return result;
    }
};