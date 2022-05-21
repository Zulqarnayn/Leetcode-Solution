class Solution {
    vector<int> dp;
    static const int inf = 1e9;
public:
    
    int calculateMinCost(int idx, vector<int>& days, vector<int>& costs) {
        if(idx >= days.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int minCost = inf;
        
        int oneDayCost = costs[0] + calculateMinCost(idx + 1, days, costs);
        
        int sevenDayCost = costs[1];
        int nextIdx = idx;
        while(nextIdx < days.size() && days[nextIdx] < days[idx] + 7) nextIdx++;
        sevenDayCost += calculateMinCost(nextIdx, days, costs);
        
        int thirtyDayCost = costs[2];
        nextIdx = idx;
        while(nextIdx < days.size() && days[nextIdx] < days[idx] + 30) nextIdx++;
        thirtyDayCost += calculateMinCost(nextIdx, days, costs);
        
        minCost = min(oneDayCost, min(sevenDayCost, thirtyDayCost));
        
        return dp[idx] = minCost;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), -1);
        return calculateMinCost(0, days, costs);
    }
};