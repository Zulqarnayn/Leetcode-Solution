class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size(), lo = 0, hi = size - 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(letters[mid] > target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        bool isTargetGreaterOrEqualLastEelment = (target >= letters[lo]) && (lo == (size - 1));
        if(isTargetGreaterOrEqualLastEelment) {
            lo = 0;
        }
        
        return letters[lo] ;
    }
};