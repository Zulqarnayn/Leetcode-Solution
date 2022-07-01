class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        
        var prefixSum: [Int] = []
        var sum = 0
        
        for item in nums {
            sum += item
            prefixSum.append(sum);
        }
        
        for (idx, _) in prefixSum.enumerated() {
            
            let leftSum = prefixSum[idx] - nums[idx];
            let rightSum = sum - (prefixSum[idx]);
            
            if leftSum == rightSum {
                return idx
            }
        }
        
        return -1
    }
}