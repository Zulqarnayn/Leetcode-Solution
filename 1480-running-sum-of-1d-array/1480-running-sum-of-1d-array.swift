class Solution {
    func runningSum(_ nums: [Int]) -> [Int] {
        var result = nums
        
        for idx in 1..<result.count {
            result[idx] += result[idx - 1]
        }
        
        return result
    }
}