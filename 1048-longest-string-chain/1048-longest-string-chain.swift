class Solution {
    private var wordMap: [String: Int] = [:]
    
    func longestStrChain(_ words: [String]) -> Int {
        var sortedWords = words.sorted{ a, b in a.count < b.count }
        
        for word in sortedWords {
            wordMap[word] = 1
        }
        
        var result = 1;
        
        for word in sortedWords {
            for idx in 0..<word.count {
                let substr = String(word.prefix(idx) + word.suffix(word.count - (idx + 1)))
                if let val = wordMap[substr] {
                    wordMap[word] = max(wordMap[word] ?? 1, val + 1)
                } else {
                    wordMap[word] = max(wordMap[word] ?? 1, 1);
                }
            }
            result = max(result, wordMap[word] ?? 1)
        }
        
        return result;
    }
}