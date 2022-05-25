class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), 
             [](const vector<int>&a, const vector<int>&b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });
        
        
        int n = envelopes.size();

        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(ans.back()<envelopes[i][1]) { 
                ans.push_back(envelopes[i][1]);
            }
            else {
                auto it=lower_bound(ans.begin(),ans.end(),envelopes[i][1]);
                *it=envelopes[i][1];
            }
        }
        return ans.size();
        
    }
};