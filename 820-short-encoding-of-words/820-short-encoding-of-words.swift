class Solution {
    func minimumLengthEncoding(_ words: [String]) -> Int {
        var reversedWords = words.compactMap{ String($0.reversed()) }
        reversedWords.sort{
            $0.count > $1.count
        }
        var markedString: [String: Bool] = [:]
        
        var result = 0
        
        for prevId in 0..<reversedWords.count {
            if markedString[reversedWords[prevId]] != nil { continue }
            for nextId in (prevId+1)..<reversedWords.count {
                if reversedWords[prevId].hasPrefix(reversedWords[nextId]) {
                    markedString[reversedWords[nextId]] = true
                }
            }
            
            result += reversedWords[prevId].count + 1
        }
        return result;
    }
}