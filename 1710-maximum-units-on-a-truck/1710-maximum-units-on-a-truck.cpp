class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &v1, const vector<int> &v2) {
            if(v2[1] == v1[1]) return v1[0] > v2[0];
            return v1[1] > v2[1];
        });
        
        int mxUnits = 0;
        
        for(auto &x: boxTypes) {
            if(truckSize == 0) break;
            
            if(x[0] <= truckSize) {
                mxUnits += x[0] * x[1];
                truckSize -= x[0];
            } else {
                mxUnits += x[1] * truckSize;
                truckSize = 0;
            }
        }
            
        return mxUnits;
    }
};