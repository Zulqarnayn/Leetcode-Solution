class Solution {
    func isIsomorphic(_ s: String, _ t: String) -> Bool {
        if s.count != t.count { return false }
        
        var sCharacterMap: [Character: String.Index] = [:]
        var tCharacterMap: [Character: String.Index] = [:]
        
        for i in s.indices {
            guard sCharacterMap[s[i]] == tCharacterMap[t[i]] else { return false; }
            
            sCharacterMap[s[i]] = i
            tCharacterMap[t[i]] = i
        }
        
        return true
    }
}