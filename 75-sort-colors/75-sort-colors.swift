class Solution {
    func sortColors(_ nums: inout [Int]) {
        var one = 0
        var two = 0
        var zero = 0
        
        for num in nums {
            zero += num == 0 ? 1 : 0
            one += num == 1 ? 1 : 0
            two += num == 2 ? 1 : 0
        }
        
        var idx = 0
        
        while((zero + one + two) != 0) {
            if zero > 0 {
                nums[idx] = 0
                zero -= 1
            } else if one > 0 {
                nums[idx] = 1
                one -= 1
            } else {
                nums[idx] = 2
                two -= 1
            }
            
            idx += 1
        }
    }
}