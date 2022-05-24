class Solution {
public:
    int findMaxCostPath(int root, vector<vector<pair<int, int>>> &relationships) {
        if(relationships[root].size() == 0) return 0;
        int maxVal = 0;
        
        for(int child = 0; child < relationships[root].size(); child++) {
            int newChild = relationships[root][child].first;
            int cost = relationships[root][child].second;
            maxVal = max(maxVal, cost + findMaxCostPath(newChild, relationships));
        }
        
        return maxVal;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<pair<int, int>>> relationships(n);
        
        for(int idx = 0; idx < informTime.size(); idx++) {
            int boss = manager[idx];
            if(boss == -1) continue;
            relationships[boss].push_back({idx, informTime[boss]});
        }
        
        return findMaxCostPath(headID, relationships);
    }
};